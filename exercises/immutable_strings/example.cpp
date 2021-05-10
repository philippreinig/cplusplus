#include <iostream>
#include "immstring.hpp"

using namespace std;
using namespace Util;

// You need to change and implement the ImmutableString class to make this
// example compile (w/o warnings)!

int main() {
  const ImmutableString s1("Hello");

  const char* str=s1.c_str();
  cout << str << endl;

  cout << "size()=" << s1.size() << endl;

  ImmutableString s2(" world!");
  ImmutableString s3 = s1.concat(s2);

  cout << s3.c_str() << endl;
  cout << "size()=" << s3.size() << endl;
}
