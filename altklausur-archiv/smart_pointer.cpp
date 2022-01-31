#include <string>
#include <iostream>
#include <memory>

using namespace std;

struct Cookie{
    string type;
    Cookie(): type("Dough"){
        cout << "Dough prepared \n";
    }

    Cookie(string type) : type(type){
        cout << type << " baked\n";
    }

    ~Cookie(){
        cout << type << " vanished\n";
    }

};

bool nobodyEatsCookies(const unique_ptr<Cookie[]>& bowl){
    return false;
}


unique_ptr<Cookie[]> mix(shared_ptr<Cookie[]> box1, int num1,
                       shared_ptr<Cookie[]> box2, int num2){

    unique_ptr<Cookie[]> kmix = unique_ptr<Cookie[]>(new Cookie[num1+num2]);;

    for(int i = 0; i < num1; ++i){
        kmix[i] = box1.get()[i];
    }

    for(int i = 0; i < num2; ++i){
        kmix[i+num1] = box2.get()[i];
    }

    return kmix;
}

bool meeting(){
    shared_ptr<Cookie[]> box1(new Cookie("Double Chocolate"));
    shared_ptr<Cookie[]> box2(new Cookie("Acacookie"));

    unique_ptr<Cookie[]> bowl = mix(box1, 1, box2, 1);

    if (nobodyEatsCookies(bowl)) return false;

    cout << bowl[1].type << " is the best one." << bowl[0].type << " is good as well. " << endl;

    return true;
}

int main(){

    return 0;
}