#include <iostream>
#include <string>

int main()
{
    //integer
    short s;
    int i;
    long l;
    long long ll;

    //float
    float f;
    double d;
    long double ld;

    //string 
    std::string str = "Hello World";
    char * c = "Hello World";
    char16_t c16;
    char32_t c32;
    wchar_t wc;

    //logic
    bool t = true;
    bool f = false;

    //auto 
    auto at = 1;
    auto at2 = 1.0;
    decltype(at) at3 = 3;

    //other
    size_t size;
    ptrdiff_t diff;

    return 0;
}