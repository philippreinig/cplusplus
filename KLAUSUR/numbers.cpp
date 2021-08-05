#include <iostream>
//Alloutputisgeneratedbyprint!
static void print(){
    static int count=0;
    std::cerr << ++count << std::endl;
}
struct A{
A(){ print();}
~A(){ print();}
A(const A&){print();}
A&operator=(const A&){print();return *this;}
};
static A*f1(){return new A();}
static void f2(A a){}
static void f3(const A&a){f2(a);}
static A f4{};
int main(){
    print();
    A a;
    A*pa=f1();
    f3(a);
    f3(*pa);
    print();
}