//
// !!! No changes until next comment !!!
//

#include <iostream>
#include <string>

struct Thing {
  Thing(const std::string& _name) : name(_name) {}

  std::string name;
};

std::ostream& operator<<(std::ostream& out, const Thing& t) {
  return out << t.name;
}

//
// !!! Edit the section up to the next comment !!!
// !!! Place required #include directives below (even if its bad style). !!!
//

// TODO:
// insert code

//
// !!! No changes below this line! !!!
//

int main() {
  Thing a("apple"), b("bottle"), c("car");

  stuff_t stuff{a, b, c};

  for (auto const& thing : stuff) { std::cout << thing << '\n'; }
  std::cout << std::flush;

  // expect constant cost for calls to stuff_t::find
  if (stuff.find(a) != stuff.end) { std::cout << "found " << a << std::endl; }
}
