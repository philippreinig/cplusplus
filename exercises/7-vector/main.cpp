#include <iostream>

#include "vector.hpp"

using Vec3 = Math::Vector<float, 3>;

int main()
{
    //Functions to test:[] reading, [] writing, -Vector to negate, Vector+Vector, Vector-Vector, Vector*int
    //Functions to implement: int*Vector

    Vec3 vector1;
    vector1[0] = 2.f;
    vector1[1] = 4.f;
    vector1[2] = 8.f;
    std::cout << "vector1: " << std::endl;
    std::cout << vector1[0] << std::endl;
    std::cout << vector1[1] << std::endl;
    std::cout << vector1[2] << std::endl;

    Vec3 vector2;
    vector2[0] = 5;
    vector2[1] = -7;
    vector2[2] = 13.5;
    std::cout << "vector2: " << std::endl;
    std::cout << vector2[0] << std::endl;
    std::cout << vector2[1] << std::endl;
    std::cout << vector2[2] << std::endl;

    Vec3 vector3 = vector1 + vector2;
    std::cout << "vector3: vector1+vector2 " << std::endl;
    std::cout << vector3[0] << std::endl;
    std::cout << vector3[1] << std::endl;
    std::cout << vector3[2] << std::endl;

    Vec3 vector4 = vector1 - vector2;
    std::cout << "vector4: vector1-vector2 " << std::endl;
    std::cout << vector4[0] << std::endl;
    std::cout << vector4[1] << std::endl;
    std::cout << vector4[2] << std::endl;

    Vec3 vector5 = -vector1;
    std::cout << "vector5: -vector1" << std::endl;
    std::cout << vector5[0] << std::endl;
    std::cout << vector5[1] << std::endl;
    std::cout << vector5[2] << std::endl;

    Vec3 vector6 = -vector2;
    std::cout << "vector6: -vector2 " << std::endl;
    std::cout << vector6[0] << std::endl;
    std::cout << vector6[1] << std::endl;
    std::cout << vector6[2] << std::endl;

    Vec3 vector7 = vector1 * 10;
    std::cout << "vector7: vector1*2 " << std::endl;
    std::cout << vector7[0] << std::endl;
    std::cout << vector7[1] << std::endl;
    std::cout << vector7[2] << std::endl;

    Vec3 vector8 = 3 * vector1;
    std::cout << "vector8: 3*vector1 " << std::endl;
    std::cout << vector8[0] << std::endl;
    std::cout << vector8[1] << std::endl;
    std::cout << vector8[2] << std::endl;  

    


    return 0;
    // Todo: test the functionality of your vector.
    // Test all written functions.
    // Return 0 if everything works, 1 if not.
}
