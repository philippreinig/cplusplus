// 1. What is missing here? Please answer briefly in a comment.
// 2. Why could this be harmful? Add a main function and explain
//    in a comment.
// 3. Please complete anything missing!

#include <string>

class Bar {
 public:
  std::string bar { "bar" };
};

class Foo {
 public:
  Foo(const std::string& foo = "foo")
      : foo_(foo), bar_(new Bar) {}
  ~Foo() { delete bar_; }

 private:
  std::string foo_;
  Bar* bar_;
};
