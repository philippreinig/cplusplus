#include <random>
#include <iostream>
#include <ctime>

int getRandomInt(int amount){
    return rand() % amount;

}

long* analyse(long* data, long amountNumbers, long amountSimulations){
    for(long i = 0; i < amountSimulations; i++){
         long randInt = getRandomInt(amountNumbers);
         data[randInt] += 1;
    }
    return data;
}

int main(){;
    srand(time(0));
    long amountNumbers = 10;
    long amountSimulations = LONG_MAX;
    long data[amountNumbers] = {0};
    long* results = analyse(data, amountNumbers, amountSimulations);
    std::cout << LONG_MAX << std::endl;
    long resultChecker = 0;
    for(long i = 0; i < amountNumbers; i++){
        std::cout << i << ": " << results[i] << std::endl;
        resultChecker += results[i];
    }
    //cout << "amountNumbers: " << amountSimulations << ", resultChecker: " << resultChecker << endl;
    std::cout << "resultsValid: " << (amountSimulations  == resultChecker) << std::endl;
    return 0;
}