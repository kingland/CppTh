## ฟังก์ชั่น (Member Function)
* สร้างไว้ในไฟล์ .cpp หรือ .cc
* const กำหนดฟังก์ชั่นไม่ให้สามารถเปลี่ยนค่าข้อมูลในออปเจ็ค

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

## ฟังก์ชัน Const (Const Function)
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

## ฟังก์ชัน Static (Static Function)
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
## ฟังก์ชั่นพารามิเตอร์ (Function Argument)
* Pass by value 
    * ค่าข้อมูลจากการก๊อปปี้
    * works on a copy of the variable
    * เรียกงานใช้งาน Copy Contructor (กรณีไม่ใช่ primitive)
    * copy constructor will be used
* Pass by reference
    * ค่าข้อมูลเป็นออริจินัล
    * works on the original variable
    * แก้ไขข้อมูลได้
    * modify it
* Pass by constant reference
    * ค่าข้อมูลเป็นออริจินัล
    * works on the original variable
    * แก้ไขข้อมูลไม่ได้
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
## ฟังก์ชันอินไลน์ (Inline Function)
* เพิ่มความเร็ว
* ขนาดโปรแกรมใหญ่ขึ้น (ข้อเสีย)

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

## การรีเทิร์นค่า (Returning)
* แบบการก๊อปปี้
```cpp
// version 1
vector<int> Max(const vector<int> & v1, const vector<int> & v2)
{
    if (v1.size() > v2.size())
        return v1; //<= copy-constructor
    else
        return v2; //<= copy-constructor
}

* แบบเรพเฟอร์เรนซ์
// version 2
const vector<int> & Max(const vector<int> & v1, const vector<int> & v2)
{
    if (v1.size() > v2.size())
        return v1; //More efficient
    else
        return v2; //More efficient
}
```