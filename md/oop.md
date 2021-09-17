## คลาส (Class)
* class คือ data + operation พิมพ์เขียวที่นำไปสร้าง อินซแตนซ์(instance) หรือ ออปเจ็ค(object)
* data คือ properties หรือ attribute บรรจุข้อมูลต่างๆ
* operation คือ method, behaviors พฤติกรรมที่ออปเจ็คสามารถกระทำได้
* data, operation มีระดับการเข้าถึงข้อมูลและฟังก์ชันการทำงาน access level
    * private -
    * public +
    * protected #
* Object = Class instance

## Encapsulation
* ออปเจ็คห่อหุ้มข้อมูล(data) และฟังก์ชันการทำงาน(functionality)

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
* มีชื่อเหมือนกับคลาส(class)
* ถูกเรียกใช้อัตโนมัติ
* ไม่มี return type
* มีได้มากกว่า 1 constructor (ไม่มีคอมไพเลอร์จะสร้างให้อัตโนมัติ)
* ไม่ควรเป็น const ฟังก์ชัน
* ควรใช้แบบ initializer list

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
* delegating constructor
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
* เรพเฟอเรนซ์ (reference) ใน constructor
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

* copy constructor ไม่มีคอมไพเลอร์จะสร้างให้
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
* มีได้ 1  destructor
* เรียกใช้อัตโนมัติเมื่อต้องการทำลายออปเจ็ค
* ไม่มีคอมไพเลอร์จะสร้าง destructor ให้เอง

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
* Stack s(10) จะเรียก destructor เมื่อสิ้นสุดการใช้งาน (pop ออกจาก stack)
* Stack* s1 = new Stack(5) เราต้องเรียก delete s1 เพื่อทำลายออปเจ็ค ระวังในการใช้งานอาจเกิด memory leak
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

## Member Function
* สร้างไว้ในไฟล์ .cpp หรือ .cc
* const ทำให้ไม่สามารถเปลี่ยนแปลงข้อมูลในออปเจ็ค

```cpp
void Employee::hire()
{
    bHired = true;
}

void Employee::getFireName() const 
{
    //ฟังก์ชัน const ไม่สามารถเปลี่ยนแปลงข้อมูลออปเจ็ค
    return mFirstName;
}

void Employee::display() const 
{
    cout << "Employee: " << getLastName() << ", "
    << getFirstName() << endl;
    cout << "-------------------------" << endl;
    cout << (bHired ? "Current Employee" :
    "Former Employee") << endl;
    cout << "Employee ID: " << getId() << endl;
    cout << "Salary: " << getSalary() << endl;
    cout << endl;
}
```
## ฟังก์ชัน Const
* ฟังก์ชั่น foo สามารถเรียกเฉพาะฟังก์ชัน const ของออปเจ็ค Employee
```cpp
void foo( const Employee& e)
{
    e.display();    // OK. display() is a const member function
    e.fire();       // ERROR. fire() is not a const member function
}

int main() 
{
    Employee emp;
    emp.setFirstName("Robert");
    emp.setLastName("Black");
    emp.setId(1);
    emp.setSalary(1000);
    emp.hire();
    emp.display();
    foo( emp );
    return 0;
}
```
## ฟังก์ชัน Static
* เข้าถึงข้อมูลเฉพาะ static เหมือนกัน
* เรียกใช้งานผ่าน class scope 
* ไม่มีพอยเตอร์ this
* มี 1 ก๊อปปี้
```cpp
//Complex.h
class Complex
{
public:
    Complex(int re=0, int im=0);
    static int getNumComplex();
// ...
private:
    static int num_complex; // <= Only one copy
    double re, im;
};

//Complex.cpp
int Complex::num_complex = 0;
int Complex::getNumComplex()
{
    return num_complex;
}

Complex::Complex(int re, int im)
{
    this->re = re;
    this->im = im;
    ++num_complex;
}

//Static method invocation
Complex z1(1,2), z2(2,3), z3;
cout<<"Number of complexs:"<<Complex::getNumComplex()<<endl;
cout<<"Number of complexes: "<<z1.getNumComplex()<<endl;

```
## Function Argument
* by value 
    * works on a copy of the variable
    * copy constructor will be used
* by reference
    * works on the original variable
    * modify it
* by constant reference
    * works on the original variable
    * not modify

```cpp
void f1(int x) {x = x + 1;} //copy constructor will be used on the argument
void f2(int& x) {x = x + 1;}
void f3(const int& x) {x = x + 1;} //ERROR: not modify
void f4(int *x) {*x = *x + 1;}
int main()
{
    int y = 5;
    f1(y);
    f2(y);
    f3(y);
    f4(&y);
    return 0;
}
```

## Friend
* function, class, data
* เข้าถึง private member ของ class
* ทำ operator overloading
```cpp
class Test{
private:
    int iValue;
    static int sValue;
public:
    Test( int in ):iValue( in ){}
    void print() const;
    static void print( const Test& what ); //static function
    friend void print( const Test& what ); //friend function
};


int Test :: sValue = 0;
void Test::print() const{
    cout<<"Member: "<<iValue<<endl;
}

void Test::print( const Test& what ){
    cout<<"Static: "<<what.iValue<<endl;
}

void print( const Test& what ){
    cout<<"Friend: "<<what.iValue<<endl;
}

int main() {
    Test test( 10 );
    test.print();
    Test::print( test );
    print( test );
}
```

## Object Life Cycle

### creation
* เรียกใช้ constructor อัตโนมัติ

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
* พอยเตอร์ this อ้างอิงออปเจ็คปัจจุบันที่ทำงานอยู่
```cpp
Stack::Stack( int mCapacity ){
 this → mCapacity = mCapacity;
 //..
}
```
### assignment
* copy-constructor
```cpp
Employee emp1(1, "Robert", "Black", 4000, true);

//copy-constructor
Employee emp2( emp1 );      //copy-constructor called
Employee emp3 = emp2;       //copy-constructor called
void foo( Employee emp );   //copy-constructor called
```
### destruction
* allocate on stack ทำลายอัตโนมัติ (ถูก pop ออกจาก stack)
* allocate on heap จะทำลายต้องสั่ง delete
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

## Inline Function
* เพิ่มความเร็ว
* ขนาดโปรแกรมใหญ่ขึ้น
```cpp
inline double square(double a)
{
    return a * a;
}

class Value
{
    int value;
public:
    inline int getValue()const{ return value; }

    inline void setValue( int value )
    {
        this->value = value;
    }
}; 
```

## Returning
```cpp
// version 1
vector<int> Max(const vector<int> & v1, const vector<int> & v2)
{
    if (v1.size() > v2.size())
        return v1; //<= copy-constructor
    else
        return v2; //<= copy-constructor
}

// version 2
const vector<int> & Max(const vector<int> & v1, const vector<int> & v2)
{
    if (v1.size() > v2.size())
        return v1; //More efficient
    else
        return v2; //More efficient
}
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

## Stack vs. Heap
* Heap –> Dynamic allocation
```cpp
void draw(){
    Point * p = new Point();
    p->move(3,3);
    //...
    delete p;
}
```

* Stack –> Automatic allocation
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
        };
        //...
    };
    //...
};
```
* คลาส B กำหนดเป็น private ในคลาส A จะเรียกใช้ได้เฉพาะคลาส A
* คลาส B กำหนดเป็น protected ในคลาส A จะเรียกใช้ได้คลาส A และคลาสที่สืบทอดจากคลาส A
* คลาส B กำหนดเป็น public ในคลาส A จะเรียกใช้ทุกคลาส (A::B b;)

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

## Lvalue
* สิ่งอ้างอิงในการเข้าถึงออปเจ็ค (อาจเข้าถึงมากกว่าหนี่งที่)
* อาจหมายถึง Location ในแมมโมรี่ที่จะใส่ค่าข้อมูล
* ชื่อ (์Named Object)
* พอยเตอร์, เรพเฟอร์เรนซ์ (pointer/reference)
* may not be move

## Lvalue Reference
* int& a รับค่าเป็น Lvalue Reference

## Rvalue
* ออปเจ็คจริง
* ออปเจ็คที่รีเทิร์นจากฟังก์ชัน (Temporary Object)
* may be move

## Rvalue Reference
* int&& a รับค่าเป็น Rvalue Reference

```cpp
int GetValue()
{
    return 10;
}

int& GetValueRef()
{
    static int value = 10;
    return value;
}

void SetValue(int i)
{
    // Lvalue & Rvalue
}

void SetValueRef(int& i)
{
    // Lvalue Reference
}

void SetValueCont(const int& i)
{
    // Lvalue & Rvalue Reference
}

void Print(std::string& str)
{
    // Lvalue Reference
}

void Print(std::string&& str)
{
    // Rvalue Reference
}

int x = 10; // x <= Lvalue, 10 <= Rvalue
10 = x; // Error : 10 not Lvalue
int y = x; // y <= Lvalue, x <= Lvalue
int z = GetValue(); // z <= Lvalue, GetValue() <= Rvalue (Tempolary Value)
int& a = 10; // Error : a <= Lvalue reference ไม่สามารถเรพเฟอเรนซ์ Rvalue
const int& b = 10; // OK: คอมไพล์เลอร์จะเปลี่ยน 10 เป็น Tempolary Value

GetValue() = 10; // Error : GetValue() not Lvalue
GetValueRef() = 10; // OK : GetValueRef() return Lvalue reference
SetValue(x); // OK: x <= Lvalue
SetValue(10); // OK: 10 <= Rvalue (Tempolary Value)
SetValueRef(x); // OK: x <= Lvalue
SetValueRef(10); // Error : SetValueRef รับอากิวเมนต์เป็น Lvalue reference, 10 <= Rvalue
SetValueCont(x); // OK
SetValueCont(10); // OK

std::string hello = "Hello";
std::string world = "World";
std::string helloworld = hello + world;
Print(helloworld); // OK : helloworld <= Lvalue , เรียกฟังก์ชัน Print(std::string& str)
Print(hello + world); // OK : hello + world <= Rvalue (Tempolary Value) , เรียกฟังก์ชัน Print(std::string&& str)
```

## Move Semantics (C++11)
* Shallow Copy
* Ownership transfer to new object
* STL ทุกคลาสรองรับ Move sementics
```cpp
class string
{
    char* data;
public:
    string( const char* );
    string( const string& );
    ~string();
}; 

string :: string(const char* p)
{
    size_t size = strlen(p) + 1;
    data = new char[size];
    memcpy(data, p, size);
}

//copy constructor
string :: string(const string& that)
{
    size_t size = strlen(that.data) + 1;
    data = new char[size];
    memcpy(data, that.data, size);
}

//string&& is an rvalue reference to a string
string :: string(string&& that) // <= move constuctor
{
    data = that.data;
    that.data = nullptr;
}

string :: ~string(){
    delete[] data;
} 
```
```cpp
Stack::Stack(Stack&& rhs){
    //move rhs to this
    this->mCapacity = rhs.mCapacity;
    this->mTop = rhs.mTop;
    this->mElements = rhs.mElements;
    //leave rhs in valid state
    rhs.mElements = nullptr;
    rhs.mCapacity = 0;
    rhs.mTop = 0;
}
```

## Copy Constructor vs Move Contructor
* **Copy Constructor** deep copy
* **Move Contructor** shallow copy + ownership transfer
```cpp
// constructor
string s=”apple”;
// copy constructor: s is an lvalue
string s1 = s;
// move constructor: right side is an rvalue
string s2 = s + s1;
```

## Passing Large Objects
* C++98
```cpp
void makeBigVector(vector<int>& out)
{
    //...
}
vector<int> v;
makeBigVector( v );
```
* C++11
```cpp
vector<int> makeBigVector()
{
    //...
}
//content of the temporary created vector is moved in v (not copy)
auto v = makeBigVector();
```

