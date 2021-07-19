#include "spaceships.cpp"




int main(){
    Cargo cargo{10};
    Laser laser_left{27, 10};
    Laser laser_right{3, 7};
    Body body{nullptr, &cargo};
    Wing left_wing{nullptr, laser_left};
    Wing right_wing{nullptr, laser_right};

    Spaceship ship{&left_wing, &right_wing, body};

    body.ship = &ship;
    left_wing.ship = &ship;
    right_wing.ship = &ship;


    Wing& leftWing = left_wing; 

    Laser laser_of_right_wing  = leftWing.ship->right->laser;
    int data = leftWing.ship->body.cargo->data;
    Body* body_ptr =  &(leftWing.ship->body);

    std::cout << typeid(body_ptr).name() << std::endl;
    std::cout << typeid(data).name() << std::endl;
    std::cout << "type of right laser: " << typeid(laser_of_right_wing).name() << std::endl;

    std::cout << " --- " << std::endl;

    std::cout << typeid(&leftWing.laser).name() << std::endl;

    std::cout << typeid(&((&leftWing)[0].ship->right)).name() << std::endl;
 }

