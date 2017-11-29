
#include "b_tree.h"
#include <iostream>
#include <random>

using std::cout;
using std::endl;

/* Testing Big O */
void O(long iterations);
void display();

int main(int argc, char *argv[])
{
    int iterations;
    /*
    if( argc == 1 )
    {
        cout << "Usage: ./b_tree [ITERATIONS]" << endl;
        return 1;
    }
    sscanf(argv[1],"%d",&iterations);
    O(iterations);
    */
    display();
    return 0;
}

void display()
{
    b_tree<int,int> tree;
    srand(clock());

    for(int i = 0; i < 100;++i)
        tree.insert(rand() % 100, i);
    tree.display(cout);
    return;
}
