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
