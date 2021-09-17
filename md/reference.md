## เรฟเฟอเร้นท์ (Reference)
* กำหนดชื่อใหม่โดยอ้างถึงออฟเจ็กตัวเดิม
* ควรกำหนดค่าเริ่มต้นใหักับ เรฟเฟอเร้นท์
* เครื่องหมาย = เป็นกำหนดค่าให้กับ เรฟเฟอเร้นท์

```cpp
int i = 10;
int &ri = i;
int &ri1; //Error: ควรมีการกำหนดค่าเริ่มต้น เรฟเฟอเร้นท์
```

## Reference Operation
* โอเปอร์เรชั่นจะกระทำกับออฟเจ็กที่ เรฟเฟอเร้นท์ อ้างอิงอยู่
```cpp
int i = 10;
int &ri = i;

++ri;
cout << i << endl; //print: 11

++i;
cout << ri << endl; //print: 12
```

## Pass By Reference
* ไม่ก๊อปปี้ ออฟเจ็ก
* ยอมให้ฟังก์ชันแก้ไขออฟเจ็กที่อ้างอิง

```cpp
void inc(int &value)
{
    value++;
}

int i = 10;
inc(i);
```

```cpp
bool isShorter(const string &s1, const string &s2)
{
    return si.size() < s2.size();
}

string str1 = "apple";
string str2 = "nut";
cout << str1 << "<" << str2 << ": " << isShorter(str1, str2);
```
