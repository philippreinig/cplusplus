#include <string>
#include <iostream>
#include <memory>

using namespace std;

struct Cookie{
    string type;
    Cookie() : type("Dough"){
        cout << "Dough prepared" << endl;
    }

    Cookie(shared_ptr<string>) : type (type){
        cout << type << " baked " << endl;
    }
    ~Cookie(){
        cout << type << " vanished " << endl;
    }

};

shared_ptr<Cookie[]> mix(shared_ptr<Cookie[]> box1, int num1, shared_ptr<Cookie[]> box2, int num2){
    shared_ptr<Cookie[]> kmix(new Cookie[num1+num2]);
    for(int i = 0; i<num1; ++i){
        kmix[i] = box1[i];
    }
    for(int i = 0; i < num2; ++i){
        kmix[i+num1] = box2[i];
    }
    return kmix;
}

bool nobodyEatsCookies(shared_ptr<Cookie[]> bowl){
    return false;
}

bool meeting(){
    shared_ptr<Cookie[]> box1({new Cookie(make_shared<string>("Bisquit")), new Cookie(make_shared<string>("Chocolate"))});
    shared_ptr<Cookie[]> box2({new Cookie(make_shared<string>("Acacookie"))});
    shared_ptr<Cookie[]> bowl = mix (box1, 2, box2, 1);
    if (nobodyEatsCookies(bowl)){
        return false;
    }
    return true;
}

int main(int argc, char* argv[]){
    meeting();

    return 0;
}
