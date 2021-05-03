#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char const* argv[]){
     vector<double> userInput = getUserValue();
     int num = 0;
     int* pointer = &num;
     cout << pointer << ": " << &pointer << endl;
} 