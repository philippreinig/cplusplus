#include <iostream>

//===================== All output is generated by print! =====================
static void print(char const* msg, char const* type= "") {
  std::cerr << msg << " " << type << std::endl;
}

//=============================================================================
template <const char* type>
class TBase {
 public:
  TBase() { print("create", type); }
  TBase(TBase const&) { print("copy", type); }
  virtual TBase& operator=(TBase const&) {
    print("assign", type);
    return *this;
  };
  virtual ~TBase() { print("destroy", type); }
};

//=============================================================================
const char char_building[]= "Building";
const char char_house[]= "House";
const char char_mansion[]= "Mansion";
const char char_shed[]= "Shed";
const char char_tower[]= "Tower";

class Building : public TBase<char_building> {};
class House : public Building, TBase<char_house> {};
class Mansion : public House, TBase<char_mansion> {};
class Shed : public House, TBase<char_shed> {};
class Tower : public Building, TBase<char_tower> {};

//=============================================================================
void part1() {
    TBase<char_building> b1{};
    TBase<char_building> b2{};
    TBase<char_house> h1{};
    TBase<char_building> b3{};
    TBase<char_house> h2{};
    TBase<char_mansion> m1{};
    TBase<char_building> b4{};
    TBase<char_house> h3{};
    TBase<char_shed> s1{};
  // TODO: add code here
}

//=============================================================================
void part2() {
  TBase<char_building>* b1 = new TBase<char_building>{};
  TBase<char_house>* h1 = new TBase<char_house>{};
  TBase<char_shed>* s1 = new TBase<char_shed>{};
  delete s1;
  delete h1;
  delete b1;
  TBase<char_building> b2{};
  TBase<char_house> h2 {};
  TBase<char_mansion> m1{};
   
}

//=============================================================================
void part3() {
   TBase<char_building>* b1 = new TBase<char_building>{};
   TBase<char_tower>* t1 = new TBase<char_tower>{};
   TBase<char_building> b2;
   TBase<char_tower> t2{};
   TBase<char_building> b3{b2};
    delete t1;
    delete b1;
    b3 = b2;

  
}

//=============================================================================
void part4() {
  TBase<char_building>* b1 = new TBase<char_building>{};
  TBase<char_house>* h1 = new TBase<char_house>{};
  TBase<char_mansion>* m1 = new TBase<char_mansion>{};
  TBase<char_building> b2 = TBase<char_building>{*b1};
  TBase<char_house> h2 = TBase<char_house>{*h1};
  delete m1;
  delete h1;
  delete b1;

  
}

//=============================================================================
// !!            Do not change the main function!
//=============================================================================

int main() {
  // ---
  print("--- part 1 ---");
  part1();
  // ---
  print("--- part 2 ---");
  part2();
  // ---
  print("--- part 3 ---");
  part3();
  // ---
  print("--- part 4 ---");
  part4();
  return 0;
}
