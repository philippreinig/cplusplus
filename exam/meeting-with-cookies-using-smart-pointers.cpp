#include <string>
#include <iostream>
#include <memory>

struct Cookie{
    std::string type;
    Cookie() : type("Dough"){
        std::cout << "Dough prepared\n";

    }

    Cookie (const std::string& type) : type(type){
        std::cout << type << " baked\n";
    }

    ~Cookie(){
        std::cout << type << " vanished\n";
    }
};

bool nobodyEatsCookies(const std::unique_ptr<Cookie[]>& bowl){
    return false;
}


 std::unique_ptr<Cookie[]> mix(const std::unique_ptr<Cookie>& box1, int num1, const std::unique_ptr<Cookie>& box2, int num2){

    std::unique_ptr<Cookie[]> kmix = std::make_unique<Cookie[]>(num1+num2);

    for(int i = 0; i < num1; ++i) kmix[i] = box1.get()[i];
    for(int i = 0; i < num2; ++i) kmix[i+num1] = box2.get()[i];

    return move(kmix);
}

bool meeting(){
    std::unique_ptr<Cookie> box1 (new Cookie ("Double Chocolate"));
    std::unique_ptr<Cookie> box2 (new Cookie ("Acacookie"));
    std::unique_ptr<Cookie[]> bowl = mix(box1, 1, box2, 1);

    if (nobodyEatsCookies(bowl)){
        return false;
    }

    return true;
}

int main(){
    meeting();
    return 0;
}