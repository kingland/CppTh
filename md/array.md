## อาเรย์ (Array)

### std::array
* แทนอาเรย์แบบเดิมของภาษ C
* เพิ่ม/ลดข้อมูลตอนรันไทม์(run time)ไม่ได้

```cpp
#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<int ,5> arr {10 ,20, 30, 40, 50};
    cout << "Array size = " << arr.size() << endl;
    for(int i=0; i<arr.size(); ++i)
    {
        cout << arr[i] << endl;
    }
    return 0;
}
```

### compile time array
* จองพื้นที่หน่วยความจำบน stack

```cpp
int ctarr[3]; // allocate on stack
```

### run time array
* จองพื้นที่หน่วยความจำบน heap

```cpp
int * rtarr = new int[3]; // allocate on heap
```

### dynamic memory management
* จองพี้นที่หน่วยความจำ (allocate)

```cpp
int * a = new int[3];
```

* คืนหน่วยความจำ (delete)
```cpp
delete [] a;
```

## array of objects
```cpp
class Point
{
    int x, y;
public:
    Point( int x=0, int y=0);
    //...
};

Point * t1 = new Point[4];
Point t1[4];
```

## array of pointers
```cpp
Point ** t2 = new Point*[ 4 ];
for(int i=0; i<4; ++i )
{
    t2[i] = new Point(0,0);
}
for( int i=0; i<4; ++i )
{
    cout<<*t2[ i ]<<endl;
}
```