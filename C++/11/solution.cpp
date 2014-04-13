#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef unsigned char uint8_t;


int vector_pass(const vector<uint8_t>&);
int maximum(int** n,const int& l); // l = length

int main(int argc, char* argv[]){

    vector<uint8_t> row;

    ifstream file ("grid.dat");

    int n;
    while (file >> n)
        row.push_back(static_cast<uint8_t>(n));

    cout << vector_pass(row) << endl;


    return 0;
}

int vector_pass(const vector<uint8_t>& row){
    
    int n = 0;
    int m = 0;
    int horizontalP, verticalP, // horizontalProduct, verticalProduct, etc...
        diagonalP, antidiagonalP;


    int *vs[] = { &horizontalP
                , &verticalP
                , &diagonalP
                , &antidiagonalP };


    // Horizontal pass (3, 0)
    // Vertical pass (0, -3)
    // Diagonal pass (3, 3)
    for (auto i : row){
        if ((i+3) % 19 == 0)
            i += 3; 

        horizontalP = row[i+0] * row[i+1]
                    * row[i+2] * row[i+3];

        verticalP = row[i+20*0] * row[i+20*1]
                  * row[i+20*2] * row[i+20*3];

        diagonalP = row[i+21*0] * row[i+21*1]
                  * row[i+21*2] * row[i+21*3];

        
        m = maximum(vs, 3);
        // Even though it has length 4 only 3 are relevant at this point.

        n = (m > n)? m : n;

    }



    // Antidiagonal pass (-3, -3)
    for (size_t i = (342); i > 4; --i){
        if ((i-3) % 20 == 0)
            i -= 3;

        antidiagonalP = row[i+19*0] * row[i+19*1]
                      * row[i+19*2] * row[i+19*3];

        n = (*vs[3] > n)? *vs[3] : n;
    }

    return n;

}

int maximum(int** n,const int& l){
    int max = 0;

    for (int i = 0; i < l; ++i)
        max = (*n[i] > max)? *n[i] : max;

    return max;
}
