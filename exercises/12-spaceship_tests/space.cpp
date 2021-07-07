#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include <stdexcept>

class SpaceObject{
    public:
        std::string getName(){
            return this->name;
        }

        virtual void getAttacked(SpaceObject& attacker, int pow) = 0;

        virtual void explode(){
            std::cout << this->getName() << " exploded!" << std::endl;
        }

        virtual bool isAlive(){
            return this->lp > 0;
        }

    protected:
        SpaceObject(std::string name_, int pos_, int lp_=1000) : name{name_} , pos{pos_}, lp{lp_}  {}
        std::string name;
        int pos;
        int lp;

    private:
};

class SpaceShip : public SpaceObject{
    public:
        SpaceShip(std::string name_, int pos_, int shield_ = 100, int amount_lasers_ = 10) : SpaceObject{name_, pos_}, shield{shield_}, amount_lasers{amount_lasers_} {}
        virtual void getAttacked(SpaceObject& attacker, int pow) override{
            if (this->lp <= 0) throw this->getName() + " exploded, cant be attacked anymore!";
            int shield_before = this->shield;
            int lp_before = this->lp;
            int shield_dmg = this->shield >= pow ? pow : this->shield;
            int attack_dmg = pow-shield_dmg;
            this->shield -= shield_dmg;
            this->lp-= attack_dmg;
            std::cout << this->getName() << " got attacked by " << attacker.getName() << "! Shield " << shield_before << " LP " << lp_before << " -[" << attack_dmg << "]-> Shield " << this->shield << " LP " << this->lp << std::endl;
            if (this->lp <= 0) this->explode();
        }

        virtual void attack(SpaceObject& target, int pow){
            try{
                target.getAttacked(*this, pow);
            }catch (std::string s){
                std::cerr << "EXCEPTION CAUGHT: " << s << std::endl;
            }
        }


    protected:
        int shield;
        int amount_lasers;
};

class DeathStar : public SpaceShip{
    public:
        DeathStar(std::string name_, int pos_, int shield_ = 1000, int amount_lasers_ = 1) : SpaceShip{name_, pos_, shield_, amount_lasers_} {}

};

class Planet : public SpaceObject{
    public: 
        Planet(std::string name_, int pos_) : SpaceObject(name_, pos_) {}
        void getAttacked(SpaceObject& attacker, int pow) override {
            if (this->lp <= 0) throw this->getName() + " exploded, cant be attacked anymore!";
            int lp_before = this->lp;
            this->lp-= pow;
            std::cout << this->getName() << " got attacked by " << attacker.getName() << "! LP: " << lp_before << "-" << pow << "->" << this->lp << std::endl;
            if (this->lp <= 0) this->explode();
        }
};