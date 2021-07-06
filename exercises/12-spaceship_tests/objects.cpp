#include "objects.hpp"
Target::Target(std::string name, int pos) = delete;
Target::~Target() = default;
void Spaceship::getAttacked(Target& attacker, int pow){
    if (attacker.)
    this->lp-=pow;
    if (this.lp <= 0) this->explode();


}