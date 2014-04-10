#include <iostream>

using namespace std;

int main(){
    int n = 26;
    int j = 0;

    while ( n > 0 ){
        j += (n % 10);
        n /= 10;
    }


    cout << j << endl;

    return 0;
}

