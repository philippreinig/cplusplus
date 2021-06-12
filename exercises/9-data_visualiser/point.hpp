#pragma once
#include <vector>
#include <iostream>

struct Point
{
    int x;
    int y;

    bool operator<(const Point& other){
        if (this->y < other.y) return true;
        else return this->y == other.y && this->x < other.x;
        // if (this-> y < other.y) return true;
        // else if (this-> y > other.y) return false;
        // else return (this -> x < other.x);
    }

    bool operator==(const Point& other){
        // bool returnVal = this->x == other.x && this->y == other.y;
        // if(returnVal) std::cout << this->string() << "==" << other.string() << std::endl;
        // else std::cout << this->string() << "!=" << other.string() << std::endl;
        return this->x == other.x && this->y == other.y;
    }

    std::string string() const{
        return ("x:" + std::to_string(x) + ",y:" + std::to_string(y));
    }
};

using PointContainer = std::vector<Point>;