#include "23tree.h"
#include <stdlib.h>
#include <fstream>
#include <time.h>
using namespace std;

bool test_tree(void);
bool test_performance(void);

int main()
{
    if( !test_tree() )
        cout << "Error testing tree" << endl;
    if( !test_performance() )
        cout << "Error testing tree's performance" << endl;

    return 0;
}

//Test the tree
bool test_tree(void)
{
    srand(time(NULL));
    tree<int> test_tree;
    int temp = 0;

    for(int i = 0; i < 20; ++i)
    {
        temp = rand() % 100;
        cout << endl
             << i+1 << ": " << "Inserting " << temp << endl;
        if( !test_tree.insert(temp) )
        {
            cout << "MAIN: insert not successful" << endl;
            return false;
        }

        cout << test_tree << endl;
        test_tree.display_ordered(cout) << endl;
    }

    tree<int> * test_tree2 = NULL;
    cout << "Copying to tree two: " << endl;
    test_tree2 = new tree<int>(test_tree);
    cout << *test_tree2 << endl;

    delete test_tree2;
    test_tree2 = NULL;

    return true;
}

bool test_performance(void)
{
    srand(time(NULL));
    tree<int> test_tree;
    int temp = 0;
    clock_t start = clock();
    ofstream fout;
    fout.open("results.txt");

    for(int i = 0; i < 10000; ++i)
    {
        temp = rand() % 10000;
        if( !test_tree.insert(temp) )
        {
            cout << "MAIN: insert not successful" << endl;
            return false;
        }
    }
    cout << "Inserted 10,000 items in: " << clock() - start << " cycles" << endl;
    test_tree.display_ordered(fout);
    return true;
}
