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
ImmutableString::ImmutableString(const ImmutableString& other)
        : m_size{other.size()}, // Order of initialization is important here!
          m_data{new char[m_size+1]} {
    // Note: The string consists of `m_size` characters and is terminated by a
    //       `\x0` character, thus: `m_size+1`.
    std::copy_n(other.c_str(), m_size + 1, m_data);
}

int getLengthOfArray(char const *array){
  int counter = 0;
  for(int i = 0; array[i] != '0'; i++){
  }
  return counter;
}

ImmutableString::ImmutableString(std::string const str): m_size(getLengthOfArray(&(str[0]))), m_data(&(str[0])){
}

ImmutableString::ImmutableString(const char* src) : m_size(getLengthOfArray(src)), m_data(src){
}


ImmutableString ImmutableString::concat(const ImmutableString& other) const {
  const int newSize = this -> m_size + other.m_size;
  const char *chars = std::strcat(this -> m_data, other.m_data);
  return ImmutableString(chars, newSize);
}

ImmutableString::~ImmutableString() {
  delete this;
}

ImmutableString::ImmutableString(char* const buf, int const len) : m_size(len), m_data(buf){
}

int ImmutableString::size() const{
  return this -> m_size;
}

char* ImmutableString::c_str() const{
  return this -> m_data;
}
} // Util
