#include "utils.hpp"
#include <iostream>
#include <vector>
using namespace std;

bool numInArray(int x, int* ptr, int n){
    for(int i = 0; i < n; i++){
        if (x==ptr[i]) return true;
    }
    return false;
}

void printArrayInt(int* ptr, int n){
    for(int i = 0; i < n; i++){
        cout << "printing array: " << endl;
        cout << "array[" << i << "] = " << ptr[i] << endl;
    }
}

void printArrayDouble(double* ptr, int n){
    for(int i = 0; i < n; i++){
        cout << "printing array: " << endl;
        cout << "array[" << i << "] = " << ptr[i] << endl;
    }
}

double* getPermutation(double* data, int n, int* perm){
    double* dataCopy = new double[n];
    for(int i = 0; i < n; i++){
        dataCopy[i] = data[perm[i]];
    }
    return dataCopy;
}

bool isPermutation(int* perm, int count){
    int* array = new int[count];
    for (int i = 0; i < count; i++){
        array[i] = -1;
    }
    for(int i = 0; i < count; i++){
        int val = perm[i];
        if (val < 0 || val >= count || numInArray(val, array, count)){
            delete[] array;
            return false;
        }else{
            array[i] = val;
        }
    }
    delete[] array;
    return true;
}

bool isSorted(double* data, int dataCount, int* perm){
    double* dataCopy = getPermutation(data, dataCount, perm);
    if (dataCount==1) return true;
    for(int i = 1; i < dataCount; i++){
        if (dataCopy[i] < dataCopy[i-1]){
            delete[] dataCopy;
            return false;
        }
    }
    delete[] dataCopy;
    return true;
}

bool isSortedDebug(double* data, int dataCount, int* perm){
    cout << "data is: " << endl;
    printArrayDouble(data, dataCount);
    cout << "perm is: " << endl;
    printArrayInt(perm, dataCount);
    double* dataCopy = getPermutation(data, dataCount, perm);
    cout << "data after reordering: " << endl;
    printArrayDouble(dataCopy, dataCount);
    if (dataCount < 0) return false;
    if (dataCount == 0 || dataCount == 1) return true;
    for(int i = 1; i < dataCount; i++){
        if (dataCopy[i] < dataCopy[i-1]) return false;
    }
    return true;
}
/*
bool getPermutation(int n){
    int* array = new int[n];
    for (int i = 0; i < n; i++){
        array[i] = -1;
    }
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        if (temp < 0 || temp >= n || numInArray(temp, array, n)){
            cout << "permutation is invalid" << endl;
            array[i] = temp;
            printArrayInt(array, i+1);
            delete[] array;
            return false;
        }else{
            array[i] = temp;
        }
    }
    printArrayInt(array, n);
    delete[] array;
    return true;
}
*/

vector<double> getUserValues(){
    vector<double> vector;
    while(1){
        double temp;
        cin >> temp;
        if (!cin.fail()){
        vector.push_back(temp);
        }else{
            cin.clear();
            cin.ignore();
            break;
        }
        
    }
    /*
    cout << "collected: " << endl;
    for(size_t i = 0; i < vector.size(); i++){
        cout << vector.at(i) << endl;
    }
    */
    return vector;
}

int* getUserPermutation(int n){
    //cout << "trying to get user permutation for size " << n << endl;
    int* array = new int[n];
    for (int i = 0; i < n; i++){
        array[i] = -1;
    }
    for(int i = 0; i < n; i++){
        //cout << "entered for loop" << endl;
        int temp;
        cin >> temp;
        if (temp < 0 || temp >= n || numInArray(temp, array, n)){
            //cout << "permutation is invalid" << endl;
            array[i] = temp;
            //printArrayInt(array, i+1);
            return array;
            delete[] array;
        }else{
            array[i] = temp;
        }
    }
    //printArrayInt(array, n);
    return array;
    delete[] array;
}

double* vectorToArrayDouble(vector<double> vector){
    int n = (int) vector.size();
    double* array = new double[n];
    for(int i = 0; i < n; i++){
        array[i] = vector[i];
    }
    return array;
}