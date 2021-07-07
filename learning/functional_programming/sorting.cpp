#include <algorithm>
#include <vector>
#include <iostream>

template<typename T>
void print_vector(std::vector<T> &vector){
    std::cout << "|";
    for(int i = 0; i < vector.size(); ++i){
        std::cout << vector[i] << "|";
    }

    std::cout << std::endl;
}

template<typename T>
int get_smallest_element(std::vector<T> &elements, bool (*less) (T, T), int start_index){
    int idx_smallest = start_index;
    for(int i = start_index; i < elements.size(); ++i){
        if (less(elements[i], elements[idx_smallest])) idx_smallest = i;
    }
    return idx_smallest;
}

template<typename T>
void swap(std::vector<T> &elements, int i, int j){
    int t = elements[i];
    elements[i] = elements[j];
    elements[j] = t;
}

template<typename T>
void sort(std::vector<T> &elements, bool (*less) (T, T)){
    for(int i = 0; i < elements.size(); ++i){
        swap(elements, i, get_smallest_element(elements, less, i));
    }
}

bool less(int i, int j){
    return i < j;
}


int main(int, char**){
    std::vector<int> vector;
    vector.push_back(1);
    vector.push_back(2);
    vector.push_back(4);
    vector.push_back(6);
    vector.push_back(19);
    vector.push_back(1);
    vector.push_back(3);
    vector.push_back(6);
    vector.push_back(5);
    vector.push_back(4);

    print_vector(vector);

    sort(vector, &less);

    print_vector(vector);

    return 0;
}