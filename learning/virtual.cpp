#include <iostream>

class Base{
	public:	
	
		virtual void method(){
			std::cout << "base" << std::endl;
		}
		
		virtual void method2(){
			std::cout << "this is the second method of class Base and it just prints rndm stuff" << std::endl;
		}

};

class Derived : public Base{
	public:
		virtual void method() override {
			std::cout << "derived" << std::endl;
		
		}

};

class Derived2 : public Derived{
	public:
		void method() override {
			std::cout << "dervived2" << std::endl;
		}
};



int main(int, char**){

	Base b;
	Base* d = new Derived();
	Base* d1 = new Derived2();
	Derived* d2 = new Derived2();
	
	b.method();
	d->method(); 
	d1->method();
	d2->method();	

	return 0;
}
