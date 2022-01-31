#include <iostream>
#include "typename.h"

    void x(int y);

int main(int, char**){
    void (*px)(int);

	std::cout << "x=" << x << "(" << type_name<decltype(x)>() << ")\n";
	std::cout << "px=" << px << "(" << type_name<decltype(px)>() << ")\n";
	
	
	return 0;
}