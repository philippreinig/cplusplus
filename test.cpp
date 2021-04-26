#include<iostream>
using namespace std;
int main(int argc, char const* argv[]){
     int num = 0;
     int* pointer = &num;
     cout << pointer << ": " << &pointer << endl;
} 