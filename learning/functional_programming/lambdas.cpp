#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template<typename T>
void print_vector(std::vector<T> vector){
    for(int i = 0; i < vector.size(); ++i){
        std::cout << vector[i] << std::endl;
    }
    std::cout << "-" << std::endl;
}

int main(){
    int comparisons = 0;
    std::vector<int> vector = {1,2,3,5,6,7,8,7,6,9,10,3};


    print_vector(vector);
    std::sort(vector.begin(), vector.end(), [&](int i, int j) -> bool {
        ++comparisons;
        return i < j;
    });
    print_vector(vector);
    std::cout << comparisons << std::endl;
}
