## ชนิดข้อมูล (Data Type)

### จำนวนเต็ม
* short
* unsigned short
* int
* unsigned int
* long
* unsigned long
* long long (C++11)
* unsigned long long (C++11)
* int8_t (cm::int8_t)
* int_least8_t (cm::int_least8_t)
* int_fast8_t (cm::int_fast8_t)
* uint8_t (cm::uint8_t)
* uint_least8_t (cm::uint_least8_t)
* uint_fast8_t (cm::uint_fast8_t)
* int16_t (cm::int16_t)
* int_least16_t (cm::int_least16_t)
* int_fast16_t (cm::int_fast16_t)
* uint16_t (cm::uint16_t)
* uint_least16_t (cm::uint_least16_t)
* uint_fast16_t (cm::uint_fast16_t)
* int32_t (cm::int32_t)
* int_least32_t (cm::int_least32_t)
* uint_fast32_t (cm::uint_fast32_t)
* int64_t (cm::int64_t) (ifndef CM_NO_INT64_T)
* int_least64_t (cm::int_least64_t) (ifndef CM_NO_INT64_T)
* int_fast64_t (cm::int_fast64_t) (ifndef CM_NO_INT64_T)
* uint64_t (cm::uint64_t) (ifndef CM_NO_INT64_T)
* uint_least64_t (cm::uint_least64_t) (ifndef CM_NO_INT64_T)
* uint_fast64_t (cm::uint_fast64_t) (ifndef CM_NO_INT64_T)
* intmax_t (cm::intmax_t)
* uintmax_t (cm::uintmax_t)
* INT8_C (Macro)
* INT16_C (Macro)
* INT32_C (Macro)
* INT64_C (Macro)
* UINT8_C (Macro)
* UINT16_C (Macro)
* UINT32_C (Macro)
* UINT64_C (Macro)
* INTMAX_C (Macro)
* UINTMAX_C (Macro)
* INTMAX_MIN (Macro)
* INTMAX_MAX (Macro)
* UINTMAX_MAX (Macro)
* INT8_MIN (Macro)
* INT8_MAX (Macro)
* INT16_MIN (Macro)
* INT16_MAX (Macro)
* INT32_MIN (Macro)
* INT32_MAX (Macro)
* INT64_MIN (Macro)
* INT64_MAX (Macro)
* UINT8_MAX (Macro)
* UINT16_MAX (Macro)
* UINT32_MAX (Macro)
* UINT64_MAX (Macro)
* INT_LEAST8_MIN (Macro)
* INT_LEAST8_MAX (Macro)
* INT_LEAST16_MIN (Macro)
* INT_LEAST16_MAX (Macro)
* INT_LEAST32_MIN (Macro)
* INT_LEAST32_MAX (Macro)
* INT_LEAST64_MIN (Macro)
* INT_LEAST64_MAX (Macro)
* UINT_LEAST8_MAX (Macro)
* UINT_LEAST16_MAX (Macro)
* UINT_LEAST32_MAX (Macro)
* UINT_LEAST64_MAX (Macro)
* INT_FAST8_MIN (Macro)
* INT_FAST8_MAX (Macro)
* INT_FAST16_MIN (Macro)
* INT_FAST16_MAX (Macro)
* INT_FAST32_MIN (Macro)
* INT_FAST32_MAX (Macro)
* INT_FAST64_MIN (Macro)
* INT_FAST64_MAX (Macro)
* UINT_FAST8_MAX (Macro)
* UINT_FAST16_MAX (Macro)
* UINT_FAST32_MAX (Macro)
* UINT_FAST64_MAX (Macro)

### จำนวนทศนิยม
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
* char16 (cm::char16)
* char32 (cm::char32)
* u16string (cm::u16string)
* u16string (std::u16string) (C++11)
* u32string (cm::u32string)
* u32string (std::u32string) (C++11)
* WCHAR_MIN (Macro)
* WCHAR_MAX (Macro)
* WINT_MIN (Macro)
* WINT_MAX (Macro)

### พอยเตอร์และอื่นๆ
* ptrdiff_t (cstddef)
* size_t (cstddef)
* max_align_t (C++11) (cstddef)
* nullptr_t (C++11) (cstddef)
* sig_atomic_t (csignal)
* NULL (cstddef) (Macro)
* SIZE_MAX (Macro)
* PTRDIFF_MIN (Macro)
* PTRDIFF_MAX (Macro)
* SIG_ATOMIC_MIN (Macro)
* SIG_ATOMIC_MAX (Macro)

```cpp
ptrdiff_t ptr_sub; //ผลต่างของพอยเตอร์
size_t len = 0; //จำนวนขนาดที่เป็นได้ตั้งแต่ 0 ขึ้นไป (unsigned integral)
```

* intptr_t
* uintptr_t
* INTPTR_MIN (Macro)
* INTPTR_MAX (Macro)
* UINTPTR_MAX (Macro)

```cpp
intptr_t ptr; //ข้อมูล convert จาก void *
uintptr_t uptr; //ข้อมูลคล้ายกับ intptr_t ใช้กรณีทำ bit operation ที่จะได้ค่าเป็น unsigned

void fn(void *address)
{
    intptr_t val = (intptr_t)address; //เก็บข้อมูลที่ convert จาก void *
}

void fn(void *address)
{
    int v = (intptr_t)address >> 1; //เมื่อ convert เป็น intptr_t สามารถดำเนินการทาง bit operation      
}

void fn(void *address) 
{
    char* pointer = (char*)((intptr_t)address << 16 >> 16);   //และ convert เป็นชนิดข้อมูลกลับได้
}
```

### อัตโนมัติ
* auto (C++11) 
* decltype(expr) (C++11)

```cpp
int i = 10;
decltype(i) j = 20;
auto k = j + i; //คอมไพเลอร์กำหนดชนิดข้อมูลอัตโนมัติ
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

void sayHello( const string& who)
{
    cout<<"Hello, "+who<<endl;
    who = "new name"; // <= Compile Error
}
```

### ขนาดข้อมูล (Size of)
* จำนวนขนาดของข้อมูลเป็นไบท์ เรียกใช้งานฟังก์ชั่น sizeof(type), sizeof(typedef)

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

map<string,string> m 
{
    {"England","London"},
    {"Hungary","Budapest"},
    {"Romania","Bucharest"}
};

struct Person
{
    string name;
    int age;
};
Person p{"John Brown", 42};
```

## C Enum 
* เปรียบเทียบข้อมูลเป็นคนละชนิดกันได้ เรียกว่าเป็น non type-safe 
* ตอนคอมไพล์จะถูกเปลี่ยนเป็น integer
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
* เปรียบเทียบต้องเป็นชนิดเดียวกัน เรียกว่าเป็น type-safe
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