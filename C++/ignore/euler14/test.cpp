#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> v_of_ints;
    for(int i = 0; i < 20; ++i)
        v_of_ints.push_back(i);
    
    int a = (v_of_ints.end() - v_of_ints.begin());

    cout << a << endl;
    return 0;
}
