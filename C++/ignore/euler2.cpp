//Project Euler problem 2, Find the sum of all the even terms in a sequence sequence which do not exceed four million
#include <iostream>

namespace {
using std::cout;
using std::endl;
}

int sumSequence();

int main()
{
    cout << sumSequence() << endl;
    return 0;
}

int sumSequence()
{

    int first       = 1,
        second      = 2,
        tmp         = 0,
        accumulator = 0;
        
    accumulator += second;
    
    while( (first + second) < 4000000 )
    {
        tmp = second;
        second += first;
        first = tmp;
        
        if( second % 2 == 0)
            accumulator += second;
    }
    
    return accumulator;
}    

