#include <iostream>

class Wing;
class Body;
class Laser;
class Cargo;
class Laser;


class Spaceship{
    public:
        Spaceship(Wing* left_, Wing* right_, Body& body_) : left{left_}, right{right_}, body{body_} {}

        Wing* left;
        Wing* right;
        Body& body;
};

class Laser{
    public:
        Laser(int amt_amunition_, int power_) : amt_amunition{amt_amunition_} , power{power_} {}
        int amt_amunition;
        int power;
};

class Wing{
    public:
        Wing(Spaceship* ship_, Laser& laser_) : ship{ship_}, laser{laser_} {}
        Spaceship* ship;
        Laser& laser;
};

class Body{
  public:
    Body(Spaceship* ship_, Cargo* cargo_) : ship{ship_}, cargo{cargo_} {}
    Spaceship* ship;
    Cargo* cargo;  
};

struct Cargo{
    Cargo(int data_) : data{data_} {}
    int data;
};