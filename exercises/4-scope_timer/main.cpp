#include <cstdlib>
#include "scopetimer.cpp"

/* TODO:
 *
 * - Utilize the ScopeTimer to measure execution times of the given code.
 *   time the whole program
 *
 * - Time the functions(or their content) work01(), work02(), work03().
 */

void work01()
{
    double numbers[10000];
    for(int i = 0; i < 10000; ++i)
    {
        numbers[i] = double(std::rand())/double(RAND_MAX);
    }
    for (int n = 10000; n > 1; n = n-1){
        for (int i = 0; i < n-1; i = i+1){
            if (numbers[i] > numbers[i+1]){
                double tmp = numbers[i];
                numbers[i] = numbers[i+1];
                numbers[i+1] = tmp;
            }
        }
    }
}

void work02()
{
    int* buf[1024];

    for(int i = 2; i < 1024; ++i)
        buf[i] = new int[i];
    for(int i = 2; i < 1024; ++i)
        delete[] buf[i];
}

// counts the number of primes in an interval
int work03( int n0, int n1 )
{
    int freq = n1-n0+1;
    for(int i = n0; i <= n1; ++i)
    {
        // Have fun: use the alternative iteration direction and see how fast
        // it gets!
        // for(int j = 2; j < i; ++j)
        for(int j = i-1; j > 1; --j)
        {
            if(i%j == 0)
            {
                --freq;
                break;
            }
       }
    }
    return freq;
}

int main(){
    ScopeTimer st1("work01", 0);
    work01();
    ScopeTimer st2("work02", 1);
    work02();
    ScopeTimer st3("work03", 2);
    work03(0, 10000);
    return 0;
}
