#include <iostream>

class Animal
{
    private:
        std::string sound = "undef_sound";
    public:
        virtual void make_sound(){};
};

class Fish : public Animal
{
    private:
        std::string sound = "Bluuub";
    public:    
        virtual void make_sound() override{
            std::cout << this->sound << std::endl;
        }
};

class Cat : public Animal
{
    private:
        std::string sound = "Miauuuu";
    public:
        virtual void make_sound() override{
            std::cout << this->sound << std::endl;
        }
};

class Lion : public Animal
{
    private:
        std::string sound = "Roarrrr";
    public:

    virtual void make_sound() override{
        std::cout << this->sound << std::endl;
    }
};

int main(){
    Lion lion;
    Cat cat;
    Fish fish;
    Animal animal;

    Animal animals[] {lion, cat, fish, animal};

    /*
    for(int i = 0; i < 4; i++){
            std:: cout << typeid(animals[i]).name() << ": ";
            animals[i].make_sound();
            std:: cout << std::endl;
    }
    */

    std:: cout << typeid(lion).name() << ": ";
    lion.make_sound();

    std:: cout << typeid(cat).name() << ": ";
    cat.make_sound();

    std:: cout << typeid(fish).name() << ": ";
    fish.make_sound();

    std:: cout << typeid(animal).name() << ": ";
    animal.make_sound();

    
}













/*
class SpaceShip
{
    public:
        virtual bool isEvil() const;
        virtual void fireLasers();
};
class ImperialShip: public SpaceShip{
    public:
        virtual bool isEvil() const override{
            return true;
        }
};
class TieFighter: public ImperialShip {
    public:
    virtual void fireLasers() override
    {
    std::cout << "pew pew!";
    }
};
*/
