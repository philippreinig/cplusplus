#include <iostream>

using namespace std;

// ---------------------------------------------------------- //
void func_one(int value)
{
  cout << "call func_one" << endl;
  cout << value << endl;
}

// ---------------------------------------------------------- //
void func_two(int value)
{
  cout << "call func_two" << endl;
  cout << value + value << endl;
}

// ---------------------------------------------------------- //
void (*signal(int signo, void (*func)(int)))(int)
{
  cout << "call signal" << endl;
  func(42);
  return &func_two;
}

// ---------------------------------------------------------- //
int main(int argc, char const *argv[])
{
  // ---
  void (*fnc_ptr1)(int) = &func_one;
  fnc_ptr1(1337);

  // ---
  void (*fnc_ptr2)(int) = signal(123, fnc_ptr1);
  fnc_ptr2(123);

  // ---
  auto fnc_ptr3 = &signal;
  fnc_ptr3(123, fnc_ptr1);

  // ---
  void (*(*fnc_ptr4)(int, void (*)(int)))(int) = &signal;
  fnc_ptr4(42, fnc_ptr1);

  cout << "Hello World!" << endl;
  return 0;
}