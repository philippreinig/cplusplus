#pragma once
#include "point.hpp"
#include <vector>

class Renderer
{
public:
    /* Initialize the Renderer with the given console size.
     * To correctly display the example data it needs to be at least 120,30.
     * Add "terminal": "externalterminal" to launch.json to get a variable size console.
     */
    Renderer(int rows, int colums);

    /* Draws the given points to cout.
     * todo: implement
     * howto: Sort the points in order of drawing them line wise: (0,0) < (10,0) < (0,1)
     *        Utilize std::sort for this. This will require an operator overload for Point.
     *        Eliminate duplicates. This can be done with std::unique and std::erase,
     *        and requires another operator overload for Point.
     */
    void draw(PointContainer& points);

    void remove_duplicates(PointContainer& points);

    void sort(PointContainer& points);

    void erase(PointContainer& points);


private:
    int m_rows;
    int m_colums;
};
