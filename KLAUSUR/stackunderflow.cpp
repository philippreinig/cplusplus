#include <iostream>
#include <string>

struct Cookies {
  void grab() {
    cookies= new std::string("my cookies");
    std::cout << "Grab " << *cookies << "\n.";
  }
  void release() {
    std::cout << "Release " << *cookies << "\n.";
    delete cookies;
  }

  std::string* cookies;
};

//
// !!! cool stuff starts here !!!
//

template <typename F>
struct cool_stuff_t {
  cool_stuff_t(F _f) : f(_f) {}
  ~cool_stuff_t() { f(); }

  F f;
};

template <typename F>
cool_stuff_t<F> but_what_is_it(F f) {
  return cool_stuff_t<F>{f};
}

static void copied_from_stackunderflow() {
  auto cookies= Cookies{};
  cookies.grab();

  auto cool_stuff= but_what_is_it([&]() { cookies.release(); });

  //
  // !!! cool stuff ends here !!!
  //
  // HELP: I copied the code snipped above... what could it be good for?
  //

  std::cout << "Hello, world!\n";
}

int main() { copied_from_stackunderflow(); }
