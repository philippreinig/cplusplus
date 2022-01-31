#include <string>
#include <iostream>
#include <memory>

using namespace std;

struct Cookie{
    string type;

    Cookie() : type ("Dough"){
        cout << "Dough prepared" << endl;
    }

    Cookie(const string& type) : type(type){
        cout << type << " baked" << endl;
    }

    ~Cookie(){
        cout << type << " vanished" << endl;
    }
};

Cookie* mix(const Cookie* box1, int num1, const Cookie* box2, int num2){

    Cookie* kmix = new Cookie[num1+num2];
    for(int i = 0; i < num1; ++i){
        kmix[i] = box1[i];
    }
    for(int i = 0; i < num2; ++i){
        kmix[i+num1] = box2[i];
    }

    return kmix;
}

bool nobodyEatsCookies(const Cookie* bowl){
    return false;
}

bool meeting() {
    Cookie box1[] = {Cookie("Bisquit"), Cookie("Chocolate")};
    Cookie box2[] = {Cookie("Acacookie")};
    Cookie* bowl = mix(box1, 2, box2, 1);
    if (nobodyEatsCookies(bowl)) return false;
    delete[] bowl;
    return true;
}

int main(){
    meeting();

    return 0;
}

