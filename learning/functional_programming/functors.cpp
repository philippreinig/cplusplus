#include <iostream>

struct print{
    void operator()(std::string str){
        std::cout << str << std::endl;
    }
};


int main(int, char**){
    print print;
    std::string test_str = "test_str";


    print(test_str);
    
    
    return 0;
}

