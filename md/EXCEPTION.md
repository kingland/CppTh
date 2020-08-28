## Exception
* ข้อผิดพลาดที่เกิดขึ้น

## Exception Handling
* การจัดการข้อผิดพลาดที่เกิดขึ้น
    * throwing
    * catching 

### ฟังก์ชัน exception
```cpp
#include <iostream>
#include <stdexcept>
using namespace std;

double div (double m, double n)
{
    if (n == 0)
    {
        throw exception(); // <= throw exception
    }
    else
    {
        return m / n;
    }
}

int main()
{
    try
    {
        cout << divide(1,0) << endl;
        return 0;
    }
    catch(const exception &e) // <= catching exception
    {
        cout << "Exception was caught!" << endl;
        return 1;
    }
}
```

### ฟังก์ชัน domain_error
```cpp
#include <iostream>
#include <stdexcept>
using namespace std;

double div (double m, double n)
{
    if (n == 0)
    {
        throw domain_error("Division by zero"); // <= throw exception
    }
    else
    {
        return m / n;
    }
}

int main()
{
    try
    {
        cout << divide(1,0) << endl;
        return 0;
    }
    catch(const exception &e) // <= catching exception
    {
        cout << e.what() << endl;
        return 1;
    }
}
```
