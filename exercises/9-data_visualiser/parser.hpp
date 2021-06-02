#pragma once

#include <string>
#include <iostream>
#include "point.hpp"

// Parser that can read Points from streams.
// The StreamT can be any iostream such as fstream or stringstream.
template <typename StreamT>
class Parser
{
public:

    /* Extracts the points from the given stream and puts them into the container.
     * todo: implement
     */
    void parse(StreamT& stream, PointContainer& container)
    {
        std::vector<std::string> lines;
        for(std::string line; std::getline(stream, line); /*nothing to increment*/){
            // std::cout << line << std::endl;
            lines.push_back(line);
        }
        // bool found_vector_with_size_not_4 = false;
        for(std::string line : lines){
            //std::cout << line << "result of splitting: ";
            std::vector<std::string> string_parts = split_string(line);
            // std::cout << line << ", x: " << string_parts[1] << ",y: " << string_parts[2] << std::endl;
            Point temp_point;
            temp_point.x = std::stoi(string_parts[1]);
            temp_point.y = std::stoi(string_parts[2]);
            container.push_back(temp_point);
            // for(int i = 0; i < string_parts.size(); i++){
            //     std::cout << "[" << i << "]= " << string_parts[i] << std::endl;
            // }
    }
    // std::cout << "found vector with size != 4: " << found_vector_with_size_not_4 << std::endl;
    }

    /* Parses a single point and puts it into the container.
     * todo: implement
     * hint: You can use for mated stream in operators (">>").
     *       Syntax errors do not need to be handled.
     */
    void parsePoint(StreamT& stream, PointContainer& container)
    {
        std::string line = "";
        std::getline(stream, line);
        std::vector<std::string> string_parts = split_string(line);
        Point temp_point;
        temp_point.x = std::stoi(string_parts[1]);
        temp_point.y = std::stoi(string_parts[2]);
        container.push_back(temp_point);
    }

private:

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

};
