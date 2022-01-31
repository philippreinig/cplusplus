#include <iostream>
#include "typename.h"

int main(){
    static int a;
    const int b = 1;
    int c;

    std::cout << "a = " << a << ", b = " << b << ", c =" << c << std::endl;

    return 0;

}