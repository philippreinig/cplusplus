#include <iostream>

using namespace std;

struct Scope{
    int id;
    Scope(int p) : id(p){
        cout << "create " << id << endl;
    }

    ~Scope(){
        cout << "destroy " << id << endl;
    }
};


void f(int n){
    cout << "enter f, n=" << n << endl;
    Scope scope(n);
    if (n==0) throw 42;
    f(n-1);
    cout << "leave f, n=" << n << endl;
}

int main(){
    try{
        Scope scope(99);
        f(2);
    }catch(int e){
        cout << "caught " << e << endl;
    }

    return 0;
}