#include <fstream>
#include <vector>
#include <iostream>
#include "parser.hpp"
//#include "renderer.hpp"

using namespace std;

/* todo: * implement missing definitions
 *       * open the file data.txt
 *       * read all points using the Parser
 *       * draw the points with the Renderer
 */

std::vector<std::string> split_string(std::string input_string){
    std::vector<std::string> parts;
    std::string temp_storage = "";
    for(char c : input_string){
        if (c == ' '){
            parts.push_back(temp_storage);
            temp_storage = "";
        }else{
            temp_storage += c;
        }
    }
    if (temp_storage != " ") parts.push_back(temp_storage);
    return parts;
}

bool string_contains_only_numbers(std::string input_string){
    return input_string.find_first_not_of("0123456789") == std::string::npos;
}


int main()
{

    PointContainer pc;
    


    std::ifstream file_reader("data.txt");
    std::vector<std::string> lines;
    for(std::string line; std::getline(file_reader, line); /*nothing to increment*/){
        // std::cout << line << std::endl;
        lines.push_back(line);
    }
    
    bool found_vector_with_size_not_4 = false;
    for(std::string line : lines){
        //std::cout << line << "result of splitting: ";
        std::vector<std::string> string_parts = split_string(line);
        if (string_parts.size() != 4) found_vector_with_size_not_4 = true;
        // std::cout << line << ", x: " << string_parts[1] << ",y: " << string_parts[2] << std::endl;
        Point temp_point;
        temp_point.x = std::stoi(string_parts[1]);
        temp_point.y = std::stoi(string_parts[2]);
        pc.push_back(temp_point);
        // for(int i = 0; i < string_parts.size(); i++){
        //     std::cout << "[" << i << "]= " << string_parts[i] << std::endl;
        // }
    }

    // std::cout << "found vector with size != 4: " << found_vector_with_size_not_4 << std::endl;
    for(Point point : pc){
        std::cout << "x:" << point.x << ",y:" << point.y << std::endl;
    }
    return 0;

}