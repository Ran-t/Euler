#include <iostream>

namespace {
using std::cout;
using std::endl;
}

int sumMults();

int main()
{
    cout << sumMults() << endl;
    return 0;
}

int sumMults()
{
    int accumulator = 0;

    for(int i = 0; i < 1000; ++i)
        if(i % 5 == 0 || i % 3 == 0) accumulator += i;

    return accumulator;
}


