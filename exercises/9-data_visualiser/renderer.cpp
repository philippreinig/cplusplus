#include <iostream>
#include <algorithm>
#include "renderer.hpp"
#include <array>

Renderer::Renderer(int rows, int colums)
    : m_rows(rows), m_colums(colums)
{
}

void Renderer::sort(PointContainer& points){
    // std::cout << "points before sorting: " << std::endl;
    // for (Point point: points){
    //     std::cout << point.string() << ",";
    // }
    // std::cout << std::endl;

    std::sort(points.begin(), points.end());

    // std::cout << "points after sorting: " << std::endl;
    // for (Point point: points){
    //     std::cout << point.string() << ",";
    // }
    // std::cout << std::endl;
}

void Renderer::erase(PointContainer& points){
    // std::cout << "size of PointContainer before erasing: " << points.size() << std::endl;
    int counter = 0;
    PointContainer temp;
    for(size_t i=0; i < points.size(); i++){
        if (temp.empty()) temp.push_back(points[i]);
        else{
            for(size_t j=0; j < temp.size(); j++){
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
    // std:: cout << "found " << counter << " duplicates." << std::endl;
    // points.erase(std::unique(points.begin(), points.end()), points.end());
    // std::cout << "size of PointContainer after erasing: " << points.size() << std::endl;
}

void Renderer::draw(PointContainer& points)
{
    erase(points);
    sort(points);
    int max_x = 0;
    int max_y = 0;
    for (Point p : points){
        if (p.x > max_x) max_x = p.x;
        if (p.y > max_y) max_y = p.y;
    }
    
    int x = ++max_x;
    int y = ++max_y;


    int* array = new int[x*y]{0};

    // std::cout << "printing array of size: " << max_x+1 << "x" << max_y+1 << std::endl;
    for(Point p : points){
        array[p.y*x+p.x] = 1;
    }
    for(int j = 0; j < y; j++){
        // std::cout << "currently at line: " << j << std:: endl;
        for(int i = 0; i < x; i++){
            // std::cout << array[i][j];
            if (array[j*x+i] == 1) std::cout << "#";
            else std::cout << " ";
        }
        std::cout << std::endl;
    }

    delete[] array;

    // std::cout << "max_x: " << max_x << std::endl;
    // std::cout << "max_y: " << max_y << std::endl;

}