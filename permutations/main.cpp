#include "utils.hpp"
#include <iostream>
#include <vector>
using namespace std;
/* todo:
 *      * read doubles from cin and put them into an array until something that
 *        is not a number is entered. (std::cin.fail() is true)
 *      * increase the array's size if necessary
 *      * reset cin (see clear() and ignore())
 *      * read in the same amount of integers
 *      * implement functions in utils.cpp
 *      * test given input with isPermutation() and isSorted()
 *      * clean up all dynamically allocated memory
 */


int main(/*int argc, char const* argv[] */) {
    //vector<double> userValues = getUserValues();
    //int size = 10;
    //cout << "please enter permutation for array size " << size << endl;
    //bool isValidPermutation = getPermutation(10);
    //cout << "is a valid Permutation: " << isValidPermutation << endl;

    double data[10]{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 10.0, 9.0};
    int array[10]{0,1,2,3,4,5,6,7,9,8};
    bool isPerm = isSorted(data, 10, array);
    cout << "isPermutation: " << isPerm << endl;
    return 0;
}


