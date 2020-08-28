#include <iostream>
// C style 
// not type-safe
enum Fruit {apple, banana, melon};
enum Vegetable {tomato, cucumber, onion};

void foo()
{
    if(apple == tomato)
    {
        std::cout << "Hurra " << std::endl;
    }
}

// C++ style
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