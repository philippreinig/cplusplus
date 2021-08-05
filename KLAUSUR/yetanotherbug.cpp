#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using duck_t = int;
using container_t = std::vector<duck_t>;
using iterator_t = typename container_t::iterator;

//
// !!! No changes above this line !!!
//

class ShootingDucks {
 public:
  ShootingDucks(int n = 10) {
    give_me_more(n);
    target_ = ducks_.end();
  }

  // Try aiming at duck with shot and return success,
  // i.e., true if a target was found.
  bool aim_at(duck_t duck) {
    target_ = std::find(ducks_.begin(), ducks_.end(), duck);

    return on_target();
  }

  // Did the last call to aim_at() (before fire()) succeed?
  bool on_target() const {
    return target_ != ducks_.end();
  }

  // Fire on target: Hits a duck if on_target(), the duck is then removed.
  // No effect if not on_target().
  // After fire() a subsequent call to on_target() returns false.
  void fire() {
    if (on_target()) {
      ducks_.erase(target_);
      target_ = ducks_.end();
    }
  }

  // We are done if there are no ducks left.
  bool done() { return ducks_.empty(); }

  // Add more ducks!
  void give_me_more(int n) {
    for (int i=0;i<n;++i) {
      ducks_.push_back(i+1);
    }
  }

 private:
  container_t ducks_;
  iterator_t  target_;
};

//
// !!! The bug hides above this line !!!
//

int main() {
  int n = 10;
  ShootingDucks game(n);

  for (int i=0;i<5;++i) {
    game.aim_at(i+1);
    game.fire();
  }

  game.aim_at(2);
  game.give_me_more(5);
  game.fire();
}
