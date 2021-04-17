#include<iostream>
using namespace std;
int main(int argc, char const* argv[]){
     std::cout << "Hello World! \n";
     std::cout << argc << "\n";
     // This is a comment

     for(int i = 0; i < argc; i++){
          std:: cout << argv[i] << "\n";
     }
     return 0;
}