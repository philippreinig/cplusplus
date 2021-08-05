#include <iostream>

template <typename F>
static int apply(F lambda, int i) {
  return lambda(i);
}

// template<int, int, int> 
struct Functor{
  Functor(int x_, int y_, int z_) : x {x_}, y{y_}, z{z_} {}
  int operator()(int i){
    y+=x;
    ++z;
    return x+i;
  }

  int x;
  int y;
  int z;
};

int main() {
  int x = 2, y = 3, z = 4;

  std::cout << "before apply\n"
            << x << '\n' << y << '\n' << z
            << "\napply\n";

  std::cout << apply([&,x](int i) {
                       y += x;
                       ++z;
                       return x + i;
                     }, 42)
            << '\n' << x << '\n' << y << '\n' << z << '\n'
            << std::flush;

;

int a = 2;
int b = 3;
int c = 4;


Functor f{a,b,c};

  std::cout << "using functor" << std::endl;
  std::cout << f(42)
            << '\n' << a << '\n' << f.y << '\n' << f.z << '\n'
            << std::flush;
}
