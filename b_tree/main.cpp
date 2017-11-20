
#include "b_tree.h"
#include <iostream>
#include <random>

using std::cout;
using std::endl;

/* Testing Big O */
void O(long iterations);

int main(int argc, char *argv[])
{
    int iterations;
    if( argc == 1 )
    {
        cout << "Usage: ./b_tree [ITERATIONS]" << endl;
        return 1;
    }
    sscanf(argv[1],"%d",&iterations);
    O(iterations);
    return 0;
}
