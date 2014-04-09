#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef unsigned char uint8_t;


int vector_pass( const vector<uint8_t>& );
int maximum(int** n,const int& l); // l = length

int main(int argc, char* argv[]){

    // Technically we only need 6 bits for positive 2-digit decimal numbers
    // but a byte is the minimum data size.
    vector<uint8_t> matrix;

    ifstream file ("grid.dat");

    int n;
    while (file >> n)
        matrix.push_back(static_cast<uint8_t>( n ));

    cout << vector_pass( matrix ) << endl;


    return 0;
}

int vector_pass( const vector<uint8_t>& matrix ){
    
    int n = 0;
    int m = 0;
    int horizontalP, verticalP, // ______P -- _____Product
        diagonalP, antidiagonalP;


    // vs = vectors
    // The C++ container called a vector is both
    // unfortunate and ironic: http://stackoverflow.com/a/758548
    int *vs[] = { &horizontalP
                , &verticalP
                , &diagonalP
                , &antidiagonalP };


    // Horizontal pass (3, 0)
    // Vertical pass (0, -3)
    // Diagonal pass (3, 3)
    for (size_t i = 0; i < matrix.size(); ++i){
        if ( (i+4) % 20 == 0)
            i += 4;

        horizontalP = matrix[i+0] * matrix[i+1]
                    * matrix[i+2] * matrix[i+3];

        verticalP = matrix[i+20*0] * matrix[i+20*1]
                  * matrix[i+20*2] * matrix[i+20*3];

        diagonalP = matrix[i+21*0] * matrix[i+21*1]
                  * matrix[i+21*2] * matrix[i+21*3];

        
        m = maximum(vs, 3);
        // Even though it has length 4 only 3 are relevant at this point.

        n = (m > n)? m : n;

    }



    // Antidiagonal pass (-3, -3)
    for (size_t i = (matrix.size() - 60); i > 4; --i){
        if ( (i-4) % 20 == 0)
            i -= 4;

        antidiagonalP = matrix[i+19*0] * matrix[i+19*1]
                      * matrix[i+19*2] * matrix[i+19*3];

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
