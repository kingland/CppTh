## Friend
* ใช้กับ ฟังก์ชั่น (Function), คลาศ (class), ข้อมูล (data)
* ใช้งาน private member ของ class
* สามารถ operator overloading

```cpp
class Test{
private:
    int iValue;
    static int sValue;
public:
    Test( int in ):iValue( in ){}
    void print() const;
    static void print( const Test& what ); //static function
    friend void print( const Test& what ); //friend function
};


int Test :: sValue = 0;
void Test::print() const{
    cout<<"Member: "<<iValue<<endl;
}

void Test::print( const Test& what ){
    cout<<"Static: "<<what.iValue<<endl;
}

void print( const Test& what ){
    cout<<"Friend: "<<what.iValue<<endl;
}

int main() {
    Test test( 10 );
    test.print();
    Test::print( test );
    print( test );
}
```