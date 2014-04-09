/*
   This program solves the Project Euler problem 7: 
        "By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th
        prime is 13.

        Whas is the 10001st prime number?"
*/

#include <iostream>
#include <vector>

using std::endl;
using std::cout;
using std::vector;

void sieve_of_eratosthenes(vector<unsigned int>&); 

int main(){
    vector<unsigned int> primes(1001);
    
    sieve_of_eratosthenes(primes);

    cout << "The 1001st prime number is: " << primes[999] << endl;

    return 0;
}

void sieve_of_eratosthenes(vector<unsigned int>& primes){
    bool sieve[



    unsigned int x = 0;
    unsigned int next_prime = 2;
    
    //Marking the list of primes()(except 2) in the array.
    while(next_prime < 1000000){
        x = next_prime;

        for(x; x < ~0; x+=x){
            sieve[x-1] = 0;
            x+=x;
        }

        x = next_prime;
        
        for(unsigned int i = 3; next_prime == x; ++i){
            if(sieve[i-1] == 1)
                next_prime = i;
        }

    }

    //Putting the list of primes()from the array in the vector.
    primes.push_back(2);

    for(unsigned int i = 3; i < sieve.size(); ++i){
        if(sieve[i-1] == 1)
            primes.push_back(i);
    }

}
