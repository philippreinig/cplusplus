#include "immstring.hpp"

// Functions from <cstring> may be used to ease working with 
// null-terminated strings.
// Further reference: https://en.cppreference.com/w/cpp/header/cstring
#include <cstring>

// This header contains std::copy_n for copying sequences of data.
// Further reference: https://en.cppreference.com/w/cpp/header/algorithm
#include <algorithm>

namespace Util {

// NOTE: Compiler errors related to this constructor provide hints to
//        where else you need to use `const`.
ImmutableString::ImmutableString(ImmutableString other)
        : m_size{other.size()}, // Order of initialization is important here!
          m_data{new char[m_size+1]} {
    // Note: The string consists of `m_size` characters and is terminated by a
    //       `\x0` character, thus: `m_size+1`.
    std::copy_n(other.c_str(), m_size + 1, m_data);
}

ImmutableString::ImmutableString(char* src) {
}

ImmutableString ImmutableString::concat(ImmutableString other) {
}

ImmutableString::~ImmutableString() {
}

ImmutableString::ImmutableString(char* buf, int len) {
}

} // Util
