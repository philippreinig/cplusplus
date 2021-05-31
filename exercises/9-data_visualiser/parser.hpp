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
    }

    /* Parses a single point and puts it into the container.
     * todo: implement
     * hint: You can use formated stream in operators (">>").
     *       Syntax errors do not need to be handled.
     */
    void parsePoint(StreamT& stream, PointContainer& container)
    {
    }
private:
};
