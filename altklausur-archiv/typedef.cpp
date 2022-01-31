#include <iostream>
#include "typename.h"

void x (int y){}

int main(int, char**){
	// int* y;
	typedef void (*XTYPE)(int);
	XTYPE a=x;
	
	std::cout << "a=" << a << "(" << type_name<decltype(a)>() << ")\n";
	// std::cout << "y=" << y << "(" << type_name<decltype(y)>() << ")\n";
	
	
	return 0;
}
