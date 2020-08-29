## ชนิดข้อมูล (Data Type)
### จำนวนเต็ม
* short
* int
* long
* long long (C++11)
### ทศนิยม
* float
* double
* long double
### ตรรกะ
* bool
### อักษร
* char
* char16_t (C++11)
* char32_t (C++11)
* wchar_t
### อัตโนมัติ
* auto (C++11) คอมไพเลอร์จะจัดการชนิดตัวแปรเอง
* decltype(expr) (C++11)

```cpp
int i = 10;
decltype(i) j = 20;
```

### ตัวแปร (Variable)
```cpp
double d; //ไม่มีการกำหนดค่าเริ่มต้น
int i = 0; //กำหนดค่าเริ่มต้น
int i {0}; //กำหนดค่าเริ่มต้น เรียกว่า uniform initialization (C++11)
```

### ค่าคงที่ (Variable Constant)
```cpp
const int N = 10;
int arr[N];

void sayHello( const string& who){
    cout<<"Hello, "+who<<endl;
    who = "new name"; // <= Compile Error
}
```

### ขนาดข้อมูล (Size of)
* จำนวนไบท์
```cpp
#include <iostream>

using namespace std;

int main()
{
    //การใช้งาน sizeof
    cout << "short : "<< sizeof(short) << "bytes" << endl;
    cout << "long  : "<< sizeof(long) << "bytes" << endl;
    cout << "long long : "<< sizeof(long long) << "bytes" << endl;
    return 0;
}
```

## ค่าเริ่มต้น
* uniform initialization (C++11)
```cpp
int n{2};

string s{"alma"};

map<string,string> m {
    {"England","London"},
    {"Hungary","Budapest"},
    {"Romania","Bucharest"}
};

struct Person{
    string name;
    int age;
};
Person p{"John Brown", 42};
```

## C Enum 
* non type-safe
* เปลี่ยนเป็น integer ตอนคอมไพล์
* สามารถนำมาเปรียบเทียบกันได้ แม้ข้อมูลจะเป็นคนละชนิดกัน
```cpp
enum Fruit {apple, banana, melon};
enum Vegetable {tomato, cucumber, onion};

void foo()
{
    if(apple == tomato)
    {
        std::cout << "Hurra " << std::endl;
    }
}
```

## C++ Enum
* type-safe
```cpp
enum class Mark {Undefined, Low, Medium, High};

Mark foo(int value) 
{
    switch(value)
    {
        case 1: case 2: return Mark::Low;
        case 3: case 4: return Mark::Medium;
        case 5: return Mark::High;
        default : return Mark::Undefined;
    }
}
```