#include <string>
#include <array>
#include "vector.hpp"

namespace Graphic{


    const int c_lineCount = 20;
    const int c_charsPerLine = 60;

    class Renderer
    {
    public:
        // draw a character at the given position in the backbuffer.
        void draw(Math::IVec2 _position, char _c);

        // Overwrites the backbuffer with spaces.
        void clear();

        // Output the backbuffer to the console.
        void swap();

    private:
        std::array < char, c_lineCount * c_charsPerLine > m_backbuffer;
    };
}