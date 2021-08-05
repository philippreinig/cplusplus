#include <iostream>

#include <algorithm>
#include <string>

void replaceX_by_Y(std::string& str) {
  std::replace(str.begin(), str.end(), 'X', 'Y'); // replace all 'x' to 'y'
}

int main(int argc, char* argv[]) {
    int n = argc-1;
    std::string args[n];
    for(int i = 1; i < argc; ++i){
        args[i-1] = argv[i];
    }
    if (n == 0) return 0;
    else{
    for(int i = 0; i < n; ++i){
        replaceX_by_Y(args[i]);
        std::cout << args[i] << " ";
    }
    std::cout << "\n";

    }


    // for(int i = 1; i < argc; ++i){
    //     std::cout << argv[i] << std::endl;
    // }
    // std::cout << "------" << std::endl;
    // for(int i = 1; i < argc; ++i){
    //     const char* word = argv[i];
    //     std::cout << "word: " << word << std::endl;
    //     int j;
    //     for(j = 0; word[j] != ' ' && word[j] != '0'; ++j){
    //         if (word[j] == 'X' ) std::cout << 'V';
    //         else std::cout << word[j];
    //     }
    //     if (word[j] == ' ') std::cout << word[j];
    // }
    // std::cout << '\n';
}
