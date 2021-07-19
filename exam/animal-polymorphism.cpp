#include <iostream>

using namespace std;

class Animal{
    public:
        virtual ~Animal(){
            cout << "die " << endl;
        }
        virtual void move() = 0;

};

class Fish : public Animal{
    public:
        ~Fish() {
            cout << "turn upside down" << endl;
        }
        virtual void move() {
            cout << "swim" << endl;
        }
};

class Bird : public Animal{
    public:
        virtual void move() {
            cout << "fly" << endl;
        }

        ~Bird(){
            cout << "fall from sky" << endl;
        }
};

class Penguin : public Bird{
    public:
        ~Penguin(){
            cout << "freeze" << endl;
        }
        virtual void move() {
            cout << "swim or walk" << endl;
        }

};

class RandoClass{
    public:
        RandoClass() = default;
        RandoClass(int i_) : i{i_} {}
        int i;
};

class RandoClassDerived : public RandoClass{
    public:
        RandoClassDerived() = default;
        RandoClassDerived(int a_, int b_) : a{a_}, b{b_} {}
        int a;
        int b;

        virtual void printMembers(){
            std::cout << a << ", " << b << std::endl;
        } 

};

int main(){

    Animal* tux = new Penguin;
    tux -> move();
    Fish* nemo = new Fish;
    nemo->move();

    RandoClassDerived* rcd_ptr = new RandoClassDerived(3,5);

    Bird* tux_as_bird = dynamic_cast<Bird*>(tux);
    Fish* tux_as_fish = dynamic_cast<Fish*>(rcd_ptr);

    std::cout << "tux_as_bird: " << typeid(tux_as_bird).name() << std::endl;
    std::cout << "tux_as_fish (should fail): " << typeid(tux_as_fish).name() << std::endl;


    delete tux;
    delete nemo;
    return 0;
}