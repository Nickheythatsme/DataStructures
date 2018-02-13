
#include "b_tree.h"
#include <iostream>
#include <random>

using std::cout;
using std::endl;
using std::cin;

/* Testing Big O */
void O(long iterations);

void test_split(int len);

int main(int argc, char *argv[])
{
    /*
    int iterations;
    if( argc == 1 )
    {
        cout << "Usage: ./b_tree [ITERATIONS]" << endl;
        return 1;
    }
    sscanf(argv[1],"%d",&iterations);
    O(iterations);
    */

    int len;
    sscanf(argv[1],"%d", &len);
    test_split(len);
    return 0;
}

int* shuffle(int len)
{
    auto *array = new int[len];
    int temp_i;
    int temp_v;
    srand(1);

    for(int i = 0; i < len; ++i)
        array[i] = i;

    for(int i = 0; i < len; ++i)
    {
        temp_i = rand() % len;

        temp_v = array[i];
        array[i] = array[temp_i];
        array[temp_i] = temp_v;
    }

    return array;
}

void test_split(int len)
{
    b_tree<int,int> tree;
    int *array = shuffle(len);
    int i = 0;


    for(; i < len; ++i)
        cout << i << ") " << array[i] << endl;
    cout << endl;

    cin.get();
    for(i = 0; i < len; ++i)
    {
        cout << i << ") Inserting: " << array[i] << endl;
        tree.insert(array[i], 1);
        tree.display(cout);
        cin.get();
    }
}
