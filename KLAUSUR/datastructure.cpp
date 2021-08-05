#include <cassert>   // assert( ... )
#include <iostream>  // std::out <<
#include <limits>    // std::numeric_limits<int>::max()
#include <memory>    // std::unique_ptr, std::make_unique
#include <vector>

//=============================================================================
// !!            Do not change the ListNode class!
//=============================================================================

struct ListNode {
  ListNode(int data) : data_(data){};

  void print() {
    std::cout << data_ << ' ';
    if (succ_->succ_ != nullptr) succ_->print();
  }

  void printDescending() {
    std::cout << data_ << ' ';
    if (pred_->pred_ != nullptr) pred_->printDescending();
  }

  const int data_= 0;
  ListNode* succ_= nullptr;  // successor
  ListNode* pred_= nullptr;  // predecessor
};

//=============================================================================

class DoubleLinkedList {
 public:
  // TODO: implement ctor
  // TODO: implement dtor
  // TODO: implement missing methods (there are at least 4)

  void print() const {
    // ---
    std::cout << "ascending:  ";
    head_->succ_->print();
    std::cout << std::endl;
    // ---
    std::cout << "descending: ";
    tail_->pred_->printDescending();
    std::cout << std::endl;
  }

 private:
  int max_value_= std::numeric_limits<int>::max();
  std::unique_ptr<ListNode> head_= std::make_unique<ListNode>(max_value_);
  std::unique_ptr<ListNode> tail_= std::make_unique<ListNode>(max_value_);
  int size_= 0;
};

//=============================================================================
// !!            Do not change the main function!
//=============================================================================

int main() {
  const std::vector<int> DATA{6,  0, 1,  1, 12, 18, 1,  0,
                              15, 3, 14, 3, 17, 4,  16, 4};

  DoubleLinkedList dlist;
  std::vector<std::unique_ptr<ListNode>> list_notes;

  int min= 0;
  int max= 18;
  int mean= (min + max) / 2;
  for (int value : DATA) {
    list_notes.emplace_back(std::make_unique<ListNode>(value));
    auto new_node= list_notes.back().get();
    if (value < mean) {
      dlist.addFromLeft(new_node);
      std::cout << "added value " << value << " from left" << std::endl;
    } else {
      dlist.addFromRight(new_node);
      std::cout << "added value " << value << " from right" << std::endl;
    }
  }

  std::cout << "There are " << dlist.size() << " nodes in the list."
            << std::endl;

  int count= dlist.count(-1);
  assert(count == 0 && "-1 is not contained in the list");
  count= dlist.count(1);
  assert(count == 3 && "1 should be contained 3 times");

  dlist.print();
}
