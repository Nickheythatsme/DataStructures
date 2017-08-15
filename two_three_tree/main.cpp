#include "23tree.h"
#include <stdlib.h>
#include <fstream>
#include <time.h>

void test_tree(void);
void test_node(void);
void test_sort(void);

int main()
{
    for(int i = 0; i < 10; ++i)
    {
        test_tree();
        //test_sort();
        //cin.ignore(100,'\n');
    }

    return 0;
}

//Test the tree
void test_tree(void)
{
    tree<int> test_tree;
    int temp = 0;

    srand(time(NULL));
    for(int i = 0; i < 30; ++i)
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
    cout << "TREE TWO: " << endl;
    test_tree2 = new tree<int>(test_tree);
    cout << *test_tree2 << endl;

    delete test_tree2;
    test_tree2 = NULL;

    return;
}

//Here we just test the node functions.
void test_node(void)
{
}

void test_sort(void)
{
    srand(time(NULL));
    int * array = new int[10];
    for(int i = 0; i < 10; ++i)
    {
        array[i] = rand() % 100;
        cout << array[i] << ", ";
    }

    cout << endl << endl;
    sort_data(array, 10);

    for(int i = 0; i < 10; ++i)
        cout << array[i] << ", ";

    cout << endl << endl;
    return;


}
