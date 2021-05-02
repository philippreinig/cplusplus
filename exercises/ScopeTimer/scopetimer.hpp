#pragma once

#include <ctime> // Use the function std::clock() to measure time.
#include <string>

// The ScopeTimer measures the time between construction and
// destruction and writes it formatted with its name to the console.
class ScopeTimer{
public: 
    // Define the constructor and destructor in scopetimer.cpp
    // ScopeTimer(const char* name);
    ScopeTimer(std::string name, int indents);
    ~ScopeTimer();
private:    
       std::string functionName;
        int start;
        int end;  
        int indents;    
    // ToDo: Data members?
};