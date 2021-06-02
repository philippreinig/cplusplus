#include <iostream>
#include <algorithm>
#include "renderer.hpp"

Renderer::Renderer(int rows, int colums)
    : m_rows(rows), m_colums(colums)
{
}

void Renderer::sort(PointContainer& points){
    std::cout << "points before sorting: " << std::endl;
    for (Point point: points){
        std::cout << point.string() << ",";
    }
    std::cout << std::endl;

    std::sort(points.begin(), points.end());

    std::cout << "points after sorting: " << std::endl;
    for (Point point: points){
        std::cout << point.string() << ",";
    }
    std::cout << std::endl;
}

void Renderer::erase(PointContainer& points){
    std::cout << "size of PointContainer before erasing: " << points.size() << std::endl;
    int counter = 0;
    PointContainer temp;
    for(long unsigned int i=0; i < points.size(); i++){
        if (temp.empty()) temp.push_back(points[i]);
        else{
            for(long unsigned int j=0; j < temp.size(); j++){
                if(points[i] == temp[j]){
                    counter++;
                    std::cout << "found same points!:" << "(" << points[i].x << "|" << points[i].y << ")" << std::endl;
                    points.erase(points.begin()+i);
                    break;
                }
            }
            temp.push_back(points[i]);
        }
    }
    std:: cout << "found " << counter << " duplicates." << std::endl;
    // points.erase(std::unique(points.begin(), points.end()), points.end());
    std::cout << "size of PointContainer after erasing: " << points.size() << std::endl;
}



void Renderer::draw(PointContainer& points)
{
    int current_x = 1;
    int current_y = 1;

    for(Point p : points){
        if (p.y > current_y){
            std::cout << std::endl;
            current_y++;
            current_x = 1;
        }
        if(p.x > current_x){
            int diff = p.x-current_x;
            for(int i = 0; i < diff; i++){
                std::cout << " ";
                current_x++;
            }
        }else{
            if(current_x != p.x) std::cout << "ERROR: currx:" << current_x << ",p.x:" << p.x <<std::endl;
            else std::cout << "*";
        }
    }

    std::cout << std::endl;
}