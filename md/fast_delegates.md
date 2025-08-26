# The Impossibly Fast C++ Delegates

## Introduction

It is an answer to the article "Member Function Pointers and the Fastest Possible C++ Delegates by Don Clugston". Don proposed an approach to delegates (further called FastDelegate) which requires the same invocation code as is produced for invocation by a pointer to member function in the simplest case (he described why some compilers produce more complex code for polymorphic classes and classes with virtual inheritance). He described why many other popular approaches are inefficient. Unfortunately, his approach is based on 'a horrible hack' (as he said). It works on many popular compilers, but is incompatible with the C++ Standard.

It seems to be true that the FastDelegate is the fastest possible way. But I suppose that such a claim needs a proof because modern C++ optimizing compilers make incredible things. I believe that **boost::function** and other dynamic memory allocation based delegates are slow, but who said there are no other good approaches?

I'm going to propose another approach, which:

1. is fast
2. doesn't use dynamic allocated memory
3. is completely compatible with the C++ Standard

## Yet Another Approach to Delegates

Let's consider a delegate which receives one argument and returns no value. It may be defined in the following way using the preferred syntax (as the **boost::function** and the FastDelegate, my library supports preferred and compatibility syntaxes; see documentation for details):

```cpp
delegate<void (int)>
```

I've simplified its code to help you understand how it works. The following code has been derived by removing unnecessary lines under and above the considered code and by replacing template parameters with concrete types.

```cpp
class delegate
{
public:
    delegate()
        : object_ptr(0)
        , stub_ptr(0)
    {}

    template <class T, void (T::*TMethod)(int)>
    static delegate from_method(T* object_ptr)
    {
        delegate d;
        d.object_ptr = object_ptr;
        d.stub_ptr = &method_stub<T, TMethod>; // #1
        return d;
    }

    void operator()(int a1) const
    {
        return (*stub_ptr)(object_ptr, a1);
    }

private:
    typedef void (*stub_type)(void* object_ptr, int);

    void* object_ptr;
    stub_type stub_ptr;

    template <class T, void (T::*TMethod)(int)>
    static void method_stub(void* object_ptr, int a1)
    {
        T* p = static_cast<T*>(object_ptr);
        return (p->*TMethod)(a1); // #2
    }
};
```

So, a delegate consists of an untyped pointer to data (because a delegate mustn't depend on the type of receiver) and a pointer to a function. This function receives the pointer to data as an extra parameter. It converts the data pointer to object pointer ('void*', unlike member pointers can be safely converted back to object pointers: [expr.static.cast], item 10) and calls the required member function.

When you create a nonempty delegate, you implicitly instantiate a stub function by getting its address (see line #1 above). It is possible because the C++ Standard allows using a pointer to member or a pointer to function as a template parameter ([temp.params], item 4):

```cpp
SomeObject obj;
delegate d = delegate::from_member<SomeObject, 
              &SomeObject::someMethod>(&obj);
```
Now 'd' is containing a pointer to stub function bound to 'someMethod' at compile time. Although a member pointer was specified, invocation at line #2 is as fast as direct method invocation (because its value is known at compile time).

As usual, the delegate may be invoked by an inline function call operator which redirects the call to the target method through the stub function:

```cpp
SomeObject obj;
d(10); // invocation of SomeObject::someMethod
       // for obj and passing them 10 as a parameter
```
Of course, it assumes an additional function call, but the overhead essentially depends on the optimizer. Actually, there may be no overhead at all.

## Performance Measurement

I've measured performance of the delegate invocation with various combinations of virtual/non-virtual methods, various numbers of arguments and with various types of inheritance. Also I've measured performance of delegates bound to a function and a static method. I've compared performance of FastDelegate with my approach using MS Visual C++ 7.1 and Intel C++ 8.0 compilers on a P4 Celeron processor.

In tangled cases, using a stub function may be a cause of a noticeable overhead (up to 5.5 times on MSVC and up to 2.4 times on Intel). But sometimes The Fastest Possible Delegates are slower (up to 15% on Intel and a little bit on MSVC). They are always slower on static members and on free functions. How could it be?

During disassembled code analysis, I've found an interesting fact. In the worst case, the compiler copies all parameters of the stub function and passes them into a target method. In some cases (if target method has no arguments or conversion is trivial), the optimizer reduces the stub function to a single jump instruction. And when a target method is inlinable, optimizer puts its code into the stub function. In this case, there is no overhead at all.

The Fastest Possible Delegates are forced to use 'thiscall' calling convention. My delegates are free to use any calling convention (except 'thiscall') including '__fastcall'. It allows passing up to two int-size arguments through registers ('thiscall' passes only 'this' pointer through ECX).

Actually, there exists a simple way to make your delegate based code extremely fast (if you really need it):

* don't use complex objects as argument types and return values (use references instead),
* don't use a virtual method as a target for delegates (because usually it may not be inlined),
* Item 2a
* put a target method implementation and delegate creation code into the same compilation unit.

You can try to use my benchmark code to measure performance on your platform and your compiler.

## Copying and Comparing Delegates

Performance of copying constructor is not the matter for both types of delegates (in contrast to delegates based on dynamic memory allocation, such as **boost::function**). Nevertheless, my delegates can be copied a bit faster because they tend to occupy less space.

My delegates cannot be compared. Comparison operators are not defined because a delegate doesn't contain a pointer to method. Pointer to a stub function can be different in various compilation units. Actually, this feature cut was the main reason why Don Clugston was not satisfied with my approach.

However, I suppose that a possibility of comparing pointer-to-methods is dangerous. It may work well until once you make some class inlinable.

I know only one reason why you may need to compare delegates. It is event syntax such as that of C#. It looks nice, but it can't be implemented without dynamic memory allocation. Moreover, in C++, it may not work well in some cases. I would like to suggest another event propagation mechanism, more suitable for C++ in my opinion.

## Portability

Although this approach is compatible with the C++ Standard, unfortunately it doesn't work on some compilers. I haven't managed to compile a test code on Borland C++. The preferred syntax doesn't work on MSVC 7.1 although it successfully compiles **boost::function** in the same syntax.

I think it is because of the rarely used language features.

## Event Library

I'm proposing an event library to demonstrate that delegates don't really need comparison operations. Actually, this event library isn't tight with my delegates. It can work with many kind of delegates including **boost::function**. Also, it can work with callback interfaces (like those of Java).

My event library provides a fast method to subscribe and unsubscribe to an event producer (even during event emitting) and doesn't use dynamically allocated memory as well (it must be important to you if you are interested in fast delegates).

This library provides two entities: event_source (it is a simplified analogue of **boost::signal**) and event_binder (an analogue of **boost::signals::scoped_connection**). Usually, an event producer keeps event_source and an event consumer keeps event_binder. A connection between a producer and a consumer exists while both event_source and event_binder exist.

You can't use an anonymous connection. Actually in **Boost**, you can use it in two ways:

1. You are absolutely sure that the event consumer exists longer than the event producer and
2. You should use **boost::signals::trackable** as the base class of an event consumer (it is possible to implement the analogue in my library, but I'm not sure it is a good idea).

You could use it in C#-style multicast delegates, but there is another problem: you must maintain pairs of actions (subscription and unsubscription), but their correctness can't be checked at compile time.

For more details, see documentation.

## Conclusion

May be some details of C++ design are not ideal, but I don't see any reason to break the C++ Standard. Moreover, sometimes hacking doesn't allow optimizers to present all of their abilities.

## References

* [Member Function Pointers and the Fastest Possible C++ Delegates" by Don Clugston](https://www.codeproject.com/Articles/11015/The-Impossibly-Fast-C-Delegates).