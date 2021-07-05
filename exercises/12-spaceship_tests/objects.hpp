#include <string>
#include <iostream>

class Target{
    public:

        virtual void getAttacked(int pow);
        void attack(Target& target);

    
    protected:
        std::string name;
        int lp;
        int pos;
    
        void explode();

    private:
        Target(std::string name, int pos);

};

class Spaceship : Target{
    protected:
        void getAttacked(int pow) override;

};