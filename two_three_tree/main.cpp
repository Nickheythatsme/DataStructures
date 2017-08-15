#include "23tree.h"
#include <stdlib.h>
#include <fstream>
using namespace std;

void test_tree(void);
void test_node(void);

int main()
{
    test_tree();

    return 0;
}

//Test the tree
void test_tree(void)
{
    tree<int> test_tree;
    tree<int> * test_tree2 = NULL;
    int temp = 0;

    srand(1);
    for(int i = 0; i < 10; ++i)
    {
        temp = rand() % 100;
        cout << endl
             << i+1 << ": " << "Inserting " << temp << endl << endl;
        if( !test_tree.insert(temp) )
            cout << "MAIN: insert not successful" << endl;

        cout << test_tree << endl;
    }

    cout << endl << "Displaying all data in order: " << endl;
    test_tree.display_ordered(cout);
    cout << endl;

    cout << "TREE TWO: " << endl;
    test_tree2 = new tree<int>(test_tree);
    cout << *test_tree2 << endl;

    return;
}

//Here we just test the node functions.
void test_node(void)
{
}

