#include "scopetimer.hpp"
#include <string>
#include <ctime>
#include <iostream>

using namespace::std;

double cpuTimeToMS(int cpuTime){
    return 1000 * cpuTime / (double) CLOCKS_PER_SEC;
}

ScopeTimer::ScopeTimer(string functionName, int indents){
            this -> functionName = functionName;
            this -> start = clock();
            this -> indents = indents;
            for(int i = 0; i < this -> indents; i++){
                cout << "   ";
            }
            cout << "function " << functionName << " started at " << cpuTimeToMS(start) << " ms" << endl;
        }

ScopeTimer::~ScopeTimer(){
            this -> end = clock();
            int difference = end - start;
            for(int i = 0; i < this -> indents; i++){
                cout << "   ";
            }
            cout << "function " << functionName << " ended at " << cpuTimeToMS(end) << " ms" << " -> function took " << cpuTimeToMS(difference) << " ms" <<endl;
        }  

