#include <iostream>
#include <unordered_map>
using namespace std;


void compute_chain_length(const int&);

unordered_map<int, int> precomputed_chains;

int main()
{   
    int highest_length = 0;
    int hl_key = 0;

    //generate an unordered_map of <starting number, collatz sequence length> pairs
    for(int i = 2; i < 1000000; ++i)
        compute_chain_length(i);
    
    //find the highest value in the unordered_map.
    for( auto it : precomputed_chains )
        if(it.second > highest_length){
            highest_length = it.second;
            hl_key = it.first;
        }

    cout << "(Starting number, length)\n(" 
         << hl_key << ", " << highest_length << ")" << endl;

    return 0;
} 

void compute_chain_length(const int& head){

    uint32_t n = head;
    uint64_t length = 0;

    while ( n != 1 ){

        if( precomputed_chains.count(n) > 0 ){

            length +=  precomputed_chains[n];

            precomputed_chains.insert(pair<int, int>(head, length));

            return;
            }

        else if( n % 2 == 0 ){
            n /= 2;
            ++length;
        }
        else{
            n = n*3+1;
            ++length;
        }
    }

    precomputed_chains.insert( pair<int, int>(head, length) );

    return;
}
