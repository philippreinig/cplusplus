#include <iostream>
#include "space.cpp"

int main(int, char**){
    int max_dmg = 100;
    int min_dmg = 1;

    SpaceShip ss("spaceship_1", 10);
    Planet planet("planet_1", 15);
    DeathStar ds("deathstar_1", 0);

    SpaceShip ss2("spaceship_2", 30);
    
        srand(time(0));

    while(planet.isAlive()){
        int r = rand() % (max_dmg + 1) + min_dmg;
        ss.attack(planet, r);
    } 
    ss.attack(planet, 10);

    while(ds.isAlive()){
        int r = rand() % (max_dmg + 1) + min_dmg;
        ss.attack(ds, r);
    }

    while(ss.isAlive()){
        int r = rand() % (max_dmg + 1) + min_dmg;
        ss2.attack(ss, r);
    }
    return 0;
}