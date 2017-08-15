#include "23tree.h"
#include <stdlib.h>
#include <fstream>
#include <time.h>

void test_tree(void);

int main()
{
    test_tree();

    return 0;
}

//Test the tree
void test_tree(void)
{
    srand(time(NULL));
    tree<int> test_tree;
    int temp = 0;

    for(int i = 0; i < 50; ++i)
    {
        temp = rand() % 100;
        cout << endl
             << i+1 << ": " << "Inserting " << temp << endl << endl;
        if( !test_tree.insert(temp) )
            cout << "MAIN: insert not successful" << endl;

        cout << test_tree << endl;
        test_tree.display_ordered(cout) << endl;
    }

    tree<int> * test_tree2 = NULL;
    cout << "Copying to tree two: " << endl;
    test_tree2 = new tree<int>(test_tree);
    cout << *test_tree2 << endl;

    delete test_tree2;
    test_tree2 = NULL;

    return;
}
