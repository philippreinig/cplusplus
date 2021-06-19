#include <iostream>
#include <string.h>
#include "renderer.hpp"

namespace Graphic{

    using namespace std;

    void Renderer::draw(Math::IVec2 _position, char _c)
    {
        size_t ind = _position[0] + _position[1] * c_charsPerLine;
        if(ind < m_backbuffer.size())
            m_backbuffer[ind] = _c;
    }

    void Renderer::swap()
    {
        cout << std::endl;
        for(int i = 0; i < c_lineCount-1; ++i)
        {
            m_backbuffer[i * c_charsPerLine + c_charsPerLine - 1] = '\n';
        }
        m_backbuffer.back() = 0;
        cout << &m_backbuffer[0];
        cout.flush();
    }

    void Renderer::clear()
    {
        memset(&m_backbuffer[0], ' ', sizeof(char)* m_backbuffer.size());
    }
}
