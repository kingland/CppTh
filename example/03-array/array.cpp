#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<int ,5> arr {10 ,20, 30, 40, 50}; // use standard array
    cout << "Array size = " << arr.size() << endl;
    for(int i=0; i<arr.size(); ++i)
    {
        cout << arr[i] << endl;
    }

    int* iarr = new int[5]; //array c style
 
    return 0;
}