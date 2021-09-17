## Hello World
* ฟังก์ชัน main แบบไม่มีพารามิเตอร์

```cpp
#include <iostream>

int main() //<= int main () { body }
{ 
    std::cout << "Hello World" << std::endl;
    return 0;
}
```

* ฟังก์ชั่น main แบบมีพารามิเตอร์
    * int argc จำนวนพารามิเตอร์ที่รับตอนรันโปรแกรม
    * char *argv[] ข้อมูล(value)พารามิเตอร์ตอนรันโปรแกรม
    * ตัวอย่าง สั่งรัน main -c -o ดังนั้น argc = 1 และ argv = [-c, -o]

```cpp
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) //<= int main (int argc, char *argv[]) { body }
{
    cout << "Hello World" << endl;
    return 0;
}
```
## I/O Stream
* Standard Output

```cpp
std::cout << "Hello World" << std::endl; // <= endl = end of line
```

* Standard Input

```cpp
int i; double d;
std::cin >> i >> d;
```

## Namespace
* ไม่ให้เกิดความสับสนในการตั้งชื่อ 
* คลาสหรือฟังก์ชั่นที่ชื่อเหมือนกันสามารถอยู่ namespace ที่ต่างกันได้

```cpp
namespace ns1
{
    void foo();
}

namespace ns2
{
    void foo();
}

//call function
ns1::foo();
ns2::foo();
```