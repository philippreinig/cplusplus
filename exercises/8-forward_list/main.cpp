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

    ForwardList<int> list2;
    list2.push_front(4);
    list2.push_front(5);

    swap(list, list2);


    std::cout << "---" << std::endl;

    for(auto i : list){
        std::cout << i << std::endl;
    }

    std::cout.flush();
    
    std::cout << "---" << std::endl;

    for(auto j : list2){
        std::cout << j << std::endl;
    }

    // ToDo: More tests!
}
