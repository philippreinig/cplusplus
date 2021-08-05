#include <iostream>
#include <memory>

using namespace std;

/**
 * replace all "*TODO*"s with
 * unique_ptr
 * shared_ptr
 * make_unique
 * make_shared
 **/

struct Fruit {
  string type_;
  bool is_smoothed_;
  Fruit(){};
  Fruit(string type) : type_(type) {
    cout << "peeled and diced the " << type << endl;
  };
  Fruit(const Fruit& other) : type_(other.type_){};
};

// put all ingredients into a bowl
std::unique_ptr<Fruit[]> collect(std::shared_ptr<Fruit> fruit1,
                          std::shared_ptr<Fruit> fruit2) {
  std::unique_ptr<Fruit[]> bowl= std::make_unique<Fruit[]>(2);

  bowl[0]= *fruit1;
  cout << fruit1->type_ << " is added" << endl;

  bowl[1]= *fruit2;
  cout << fruit2->type_ << " is added" << endl;

  return move(bowl);
}

// empty the bowl into the blender
std::unique_ptr<Fruit[]> smooth(std::unique_ptr<Fruit[]> fruits, int fruit_count) {
  std::unique_ptr<Fruit[]> smoothed_fruits(move(fruits));
  for (int i= 0; i < fruit_count; ++i) {
    smoothed_fruits[i].is_smoothed_= true;
  }
  return move(smoothed_fruits);
}

// drink the smoothie
void drink(std::unique_ptr<Fruit[]> smoothie, int size) {
  if (smoothie[1].is_smoothed_) {
    cout << "That was delicious! It tasted like: " << endl;
    for (int i= 0; i < size; i++) { cout << smoothie[i].type_ << endl; }
  } else {
    cout << "ehh" << endl;
  }
}

std::unique_ptr<Fruit[]> mixSmoothie(int size) {
  // supply (oranges und banana)
  auto orange_stock= std::make_shared<Fruit>("orange");
  auto banana_stock= std::make_shared<Fruit>("banana");

  // take one fruit from every type from the stock
  std::unique_ptr<Fruit[]> bowl= collect(orange_stock, banana_stock);

  // put all fruits into the blender
  std::unique_ptr<Fruit[]> smoothie= smooth(move(bowl), size);

  // return the smoothie to the customer
  return move(smoothie);
}

int main() {
  // a customer orders a smoothie with two ingredients
  std::unique_ptr<Fruit[]> smoothie= mixSmoothie(2);

  // the customer drinks the smoothie
  drink(move(smoothie), 2);

  // afterward he orders another smoothie
  if (smoothie.get() == nullptr) {
    cout << "Another one, please!" << endl;
    std::unique_ptr<Fruit[]> new_smoothie= mixSmoothie(2);
    drink(move(new_smoothie), 2);
  }

  return 0;
}