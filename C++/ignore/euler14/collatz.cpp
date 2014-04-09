//collatz.cpp -- 
//        This program solves the project euler problem 14: "Which starting number, under one million, produces the longest collatz chain?". Using a hash table (unordered_map) to speed up the process since we don't actually need the collatz chains themselves; just the starting number and lengths.
#include <iostream>
#include <vector>
#include <unordered_map>

using std::endl;
using std::cout;
using std::vector;
using std::unordered_map;
using std::pair;

unordered_map<int, int> precomputed_chains;

int compute_chain_length(int);

int main()
{   
    int highest_length = 0;
    int hl_key = 0;

    //generate an unordered_map of <starting number, collatz sequence length> pairs
    for(int i = 2; i < 1000000; ++i)
        compute_chain_length(i);
    
    //find the highest value in the unordered_map.
    for(map_of_ints::const_iterator it = precomputed_chains.begin(); it != precomputed_chains.end(); ++it)
        if(it->second > highest_length){
            highest_length = it-> second;
            hl_key = it->first;
        }

    cout << "{Starting number, length} = {" << hl_key << ", " << highest_length << "}" << endl;

    return 0;
} 

int compute_chain_length(int n){
    vector<int> chain;
    chain.push_back(n);
    
    int newSize;

    while (n != 1){
        if(precomputed_chains.count(n) > 0){
            newSize = (chain.size() + precomputed_chains[n]);
            precomputed_chains.insert(pair<int, int>(chain.front(), newSize));
            return newSize;
            }
        else if(n % 2 == 0){
            n /= 2;
            chain.push_back(n);
        } 
        else {
            n = (n * 3 + 1);
            chain.push_back(n);
        }
    }

    precomputed_chains.insert(pair<int, int>(chain.front(), chain.size()));

    return chain.size();
}
