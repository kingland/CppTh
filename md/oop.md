## คลาส (Class)
* class คือ data และ operation 
* class คือ พิมพ์เขียว(รูปแบบโครงสร้างหรือต้นแบบ)ที่นำไปสร้าง อินซแตนซ์(instance) หรือ ออปเจ็ค(object)
* data คือ properties หรือ attribute บรรจุข้อมูลต่างๆ
* operation คือ method, behaviors พฤติกรรมที่ออปเจ็คสามารถกระทำได้
* data, operation ระดับการเข้าถึงข้อมูลและฟังก์ชันการทำงาน access level
    * private -
    * public +
    * protected #
* ออปเจ็ค (Object) = อินซแตนซ์ (Class instance)

## Encapsulation
* ออปเจ็คห่อหุ้มข้อมูล(data) และฟังก์ชันการทำงาน(functionality)

## คลาส C++ ที่ดีควรมี
* implicit constructor
```cpp
T :: T(){ … }
```
* destructor
```cpp
T :: ~T(){ … }
```
* copy constructor
```cpp
T :: T( const T& ){ … }
```
* assignment operator
```cpp
T& T :: operator=( const T& ){ … }
```

## Class Declaration 
* ส่วน interface หรือ abstract ใน C++
* ไฟล์ .h หรือ .hpp 

```cpp
class Employee
{
public:
    Employee(); // <= constructor

    void display() const; // <= methods
    void hire();
    void fire();
    //get set
    void setFirstName(string firstname);
    void setLastName(string lastname);
    string getFirstName() const;
    string getLastName() const;
    int getSalary() const;
    bool getIsHire() const;
    int getId() const;

private:
    int mId; // <= data members
    string mFirstName;
    string mLastName;
    int mSalary;
    bool bHired;
}
```

## Class Definition
* ส่วน implementation ใน C++
* ไฟล์ .cpp หรือ .cc

## Constructor
* กำหนดค่าเริ่มต้น member data
* ชื่อเหมือนกับชื่อคลาส(class)
* จะถูกเรียกใช้งานอัตโนมัติ
* ไม่มี return type
* สามารถมีมากกว่า 1 Constructor (ไม่ระบุคอมไพเลอร์จะสร้างให้อัตโนมัติ)
* ไม่เป็น const ฟังก์ชัน
* แนะนำใช้แบบ initializer list

```cpp
//constructor
Employee::Employee() 
: mId(-1), mFirstName(""), mLastName(""), mSalary(0), bHired(false) // <=  initializer list
{}

//constuctor
Employee::Employee() // <= member assign
{
    mId = -1;
    mFirstName = "";
    mLastName = "";
    mSalary = 0;
    bHired = false;
}
```
* default และ delete
```cpp
//constructor default and delete (C++11)
class X
{
    int i = 4;
    int j {5};
public:
    X(int a) : i(a) {} // i = a, j = 5
    //automatic generation default constructor
    X() = default;  // i = 4, j = 5
};

class X
{
public:
    X(double x){}
};

X dx(3.14); // OK
X ix(10);   // OK int → double conversion

class X
{
public:
    X(int x) = delete;
    X(double x) {}
};

X ix(10); //ERROR
X dx(3.14); // OK
```
* delegating constructor (C++11)
```cpp
//delegating constructor (C++11)
class SomeType
{
private:
    int number;
public:
    SomeType(int newNumber) : number(newNumber) {}
    SomeType() : SomeType(42) {}
};
```
* เรพเฟอเรนซ์ & (reference) ในคอนสตัคเตอร์
```cpp
//constructor reference value can't assign to member
class Ref
{
public:
    Ref(int& ref)
    {
        mI = ref; //OK
        mCi = ref; //ERROR: const member not assign
        mRi = ref; //ERROR: uninitialized 
    }

    //ctor initializer
    //Ref(int& ref) : mI(ref), mCi(ref), mRi(ref){}

private:
    int mI;
    const int mCi;
    int &mRi;
}
```

* ก๊อปปี้คอนสตัคเตอร์(Copy Constructor) ไม่ระบุคอมไพเลอร์จะสร้างให้อัตโนมัติ
```cpp
Employee emp1(1, "Robert", "Black", 4000, true);

//copy-constructor
Employee emp2( emp1 );      //copy-constructor called
Employee emp3 = emp2;       //copy-constructor called
void foo( Employee emp );   //copy-constructor called
```
* ตัวอย่าง copy-constructor
```cpp
//Stack.h
#ifndef STACK_H
#define STACK_H
class Stack
{
public:
    Stack( int inCapacity );
    void push( double inDouble );
    double top() const;
    void pop();
    bool isFull() const;
    bool isEmpty()const;

private:
    int mCapacity;
    double * mElements;
    double * mTop;
};
#endif /* STACK_H */

//Stack.cpp
#include "Stack.h"

Stack::Stack( int inCapacity )
{
    mCapacity = inCapacity;
    mElements = new double [ mCapacity ];
    mTop = mElements;
}

Stack::Stack( const Stack& s ) // <= copy-constructor
{
    mCapacity = s.mCapacity;
    mElements = new double[ mCapacity ];
    int nr = s.mTop - s.mElements;
    for( int i=0; i<nr; ++i ){
        mElements[ i ] = s.mElements[ i ];
    }
    mTop = mElements + nr;
}

void Stack::push( double inDouble )
{
    if( !isFull()){
        *mTop = inDouble;
        mTop++;
    }
}
```
## Destructor
* สามารถมีมากว่า 1  Destructor
* เรียกใช้งานอัตโนมัติเมื่อต้องการทำลายออปเจ็ค (Object)
* ไม่ระบุคอมไพเลอร์จะสร้าง Destructor ให้อัตโนมัติ

```cpp
Stack::~Stack()
{
    if( mElements != nullptr )
    {
        delete[] mElements;
        mElements = nullptr;
    }
}
```
* Stack s(10) เรียกใช้งาน Destructor เมื่อสิ้นสุดการใช้งาน (pop ออกจาก stack)
* Stack* s1 = new Stack(5) ต้องเรียกใช้งาน delete s1 เพื่อทำลายออปเจ็ค ระวังในการใช้งานอาจเกิด memory leak
```cpp
{ // block begin
    Stack s(10); // s: constructor
    Stack* s1 = new Stack(5);// s1: constructor
    s.push(3);
    s1->push(10);
    delete s1; //s1: destructor
    s.push(16);
} // block end //s: destructor
```

## Member initialization (C++11)
```cpp
class C
{
string s ("abc");
double d = 0;
char * p {nullptr};
int y[4] {1,2,3,4};

public:
    C();
}
```

## Object Life Cycle

### การสร้างออปเจ็ก (Object Creation)
* เรียกคอนสตัคเตอร์ (Constructor) อัตโนมัติ

```cpp
int main()
{
    Employee emp; //allocate on stack
    emp.display();

    Employee* demp = new Employee(); //allocate on heap
    //.....
    delete demp;
    
    return 0;
}
```
* การกำหนด default value (C++11) ต้องกำหนด method declaration (ไฟล์.h)
```cpp
struct Point{
    int x, y;
    Point ( int x = 0, int y = 0 ): x(x), y(y){}
};

class Foo{
    int i {};
    double d {};
    char c {};
    Point p {};
public:
    void print(){
        cout <<"i: "<<i<<endl; //i: 0
        cout <<"d: "<<d<<endl; //d: 0
        cout <<"c: "<<c<<endl; //c: 
        cout <<"p: "<<p.x<<", "<<p.y<<endl; //p: 0, 0
    }
};

```

* this คือ พอยเตอร์ (Pointer) อ้างอิงออปเจ็คปัจจุบันที่ทำงานอยู่

```cpp
Stack::Stack( int mCapacity ){
 this → mCapacity = mCapacity;
 //..
}
```
### การกำหนดค่า (Assignment)
* กำหนดค่าโดยใช้ copy-constructor

```cpp
Employee emp1(1, "Robert", "Black", 4000, true);

//copy-constructor
Employee emp2( emp1 );      //copy-constructor called
Employee emp3 = emp2;       //copy-constructor called
void foo( Employee emp );   //copy-constructor called
```
### การทำลายออปเจ็ค (Object Destruction)
* กรณีใช้งานเมมโมรี่บน stack (allocate on stack) ทำลายอัตโนมัติถูก pop ออกจาก stack
* กรณีใช้งานเมมโมรี่บน heap (allocate on heap) การทำลายต้องคำสั่ง delete

```cpp
{ // block begin
    Stack s(10); // s: constructor 
    Stack* s1 = new Stack(5);// s1: constructor
    s.push(3);
    s1->push(10);
    delete s1; //s1: destructor
    s.push(16);
} // block end //s: destructor
```

```cpp
vector<int> selectOdd(const vector<int>& v){
    vector<int> odds;
    for( int a: v ){
        if (a % 2 == 1 ){
            odds.push_back( a );
        }
    }
    return odds;
}
//...
vector<int> v(N);
for( int i=0; i<N; ++i){
    v.push_back( rand()% M);
}
vector<int> result = selectOdd( v ); // <=copy constructor invocation
```

## Allocate on Stack vs. Allocate on Heap
* Allocate on Heap –> Dynamic allocation

```cpp
void draw(){
    Point * p = new Point();
    p->move(3,3);
    //...
    delete p;
}
```

* Allocate on Stack –> Automatic allocation

```cpp
void draw()
{
    Point p;
    p.move(6,6);
    //...
}
```

## Classes vs. Structs
* class = data + method
* class = default access private
* struct = mostly data + convenience method
* struct = default access public
* class, struct สามารถทำงานร่วมกัน

```cpp
class list
{
private:
    struct node
    {
        node *next;
        int val;
        node( int val = 0, node * next = nullptr):val(val), next(next){}
    };
    node * mHead;
public:
    list ();
    ~list ();
    void insert (int a);
    void printAll()const;
};
```

## Nested Classes
* คลาสซ้อนคลาส
* คลาส B กำหนดเป็น private ในคลาส A จะเรียกใช้ได้เฉพาะคลาส A
* คลาส B กำหนดเป็น protected ในคลาส A จะเรียกใช้ได้คลาส A และคลาสที่สืบทอดจากคลาส A
* คลาส B กำหนดเป็น public ในคลาส A จะเรียกใช้ทุกคลาส (A::B b;)

```cpp
// Version 1
class Queue
{
private:
    // class scope definitions
    // Node is a nested structure definition local to this class
    struct Node {Item item; struct Node * next;};
    ...
};

// Version 2
class Queue
{
// class scope definitions
// Node is a nested class definition local to this class
    class Node
    {
    public:
        Item item;
        Node * next;
        Node(const Item & i) : item(i), next(0) { }    
        //...
    };
    //...
};
```
