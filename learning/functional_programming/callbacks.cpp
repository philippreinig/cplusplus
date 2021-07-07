#include <iostream>
#include <vector>

int increment (int x){
    return ++x;
}

std::string calc_progress(double finished, double total){
    return "progress: " + std::to_string((finished/total*100)) +  "%";
}


void increment_all_ints(std::vector<int>& ints, std::string (*print_progress_ptr) (double, double)){
    size_t n = ints.size();
    if (!print_progress_ptr) std::cout << "increment_all_ints: no progress updates, ptr given is invalid";
    for(size_t i = 0; i < n; ++i){
        std::cout << ints[i] << " -> " << (ints[i] = increment(ints[i]))  << (print_progress_ptr ? " [" + calc_progress(double(i+1), double(n))  + "]" : "") << std::endl;
    }
}


template <typename T>
void print_all_elements_of_vector(std::vector<T> vector){
    size_t n = vector.size();
    for(size_t i = 0; i < n; ++i){
        std::cout << vector[i] << std::endl;
    }
}

std::vector<int> fill_vector_with_ints(int n){
    std::vector<int> vector(n);
    for(int i = 0; i < n; ++i){
        vector[i] = i+1;
    }
    return vector;
}

int main(int argc, char** argv){
    int (*increment_functptr) (int) = &increment;
    int test_int = 2;
    std::cout << "increment(" << test_int << ")=" << increment(test_int) << std::endl;
    std::cout << "increment_functptr(" << test_int << ")=" << increment_functptr(test_int) << std::endl;
    // ====================================================================== //
    int vector_length = 10;
    std::vector<int> ints = fill_vector_with_ints(vector_length);
    std::string (* calc_progress_ptr) (double, double) = &calc_progress;
    print_all_elements_of_vector<int>(ints);
    increment_all_ints(ints, calc_progress_ptr);
    print_all_elements_of_vector<int>(ints);
    return 0;
}