#include <fstream>
#include <vector>
#include <iostream>
#include "parser.hpp"
#include "renderer.hpp"

using namespace std;

/* todo: * implement missing definitions
 *       * open the file data.txt
 *       * read all points using the Parser
 *       * draw the points with the Renderer
 */


int main()
{
    PointContainer pc;
    std::ifstream file_reader("data.txt");
    Parser<ifstream> parser;
    parser.parse(file_reader, pc);  

    Renderer renderer(0, 0);
    renderer.erase(pc);
    renderer.sort(pc);
    renderer.draw(pc);
    return 0;

}