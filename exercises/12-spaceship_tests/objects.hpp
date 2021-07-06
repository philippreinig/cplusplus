#include <string>
#include <iostream>

class Target{
    public:

        virtual void getAttacked(int pow);
        virtual void attack(Target& target, int pow);

    
    protected:
        std::string name;
        int lp;
        int pos;
    
        void explode();

    private:
        Target(std::string name_, int pos_);
        ~Target();

};

class Spaceship : Target{
    public: 
        using Target::Target(std::string name_, int pos_);

    protected:
        void getAttacked(int pow) override;
        int amnt_lasers;
        int shield;
};

class Planet : Target{
    protected:
        void getAttacked(int pow) override;
    private:
        void attack(Target& target, int pow) override;
};

class Deathstar : Spaceship{





};
