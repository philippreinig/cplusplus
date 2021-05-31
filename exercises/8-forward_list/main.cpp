#include "forwardlist.hpp"
#include <iostream>

using namespace a08;

int main()
{
    ForwardList<int> list;

    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    for(auto i: list){
        std::cout << i << "\n";
    }

    // ToDo: More tests!
}
