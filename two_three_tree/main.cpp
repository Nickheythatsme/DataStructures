#include "two_three_tree.h"
#include <fstream>

//Example to show how the tree works!
bool test_tree(void);
//Test entering 100,000 int objs into the tree. We report how long it took.
bool test_performance(void);
//Bubble sort. Test this if you dare. It takes a ridiculously long time.
//It's just for comparison.
bool test_bubble_sort(void);

using namespace std;
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

    return true;
}

#define MAX 100000
bool test_performance(void)
{
    srand(clock());
    tree<int> test_tree;
    int temp = 0;
    std::ofstream fout;
    fout.open("results.txt");
    clock_t total = 0;
    clock_t start = clock();

    for(int i = 0; i < MAX; ++i)
    {
        temp = rand() % 100000;
        if( !test_tree.insert(temp) )
        {
            cout << "MAIN: insert not successful" << endl;
            return false;
        }
    }
    
    total = clock() - start;
    cout << "Inserted " << MAX << " items in: " << total << " cycles" 
         << " (" << (float)total/CLOCKS_PER_SEC << " seconds)" << endl;
    test_tree.display_ordered(fout);
    return true;
}

//Bubble sort. Test this if you dare. It takes a ridiculously long time.
//It's just for comparison.
bool test_bubble_sort(void)
{
    int * array = new int[MAX];
    int temp = 0;
    clock_t total = 0;
    clock_t start = clock();

    for(int i = 0; i < MAX; ++i)
    {
        temp = rand() % 100000;
        array[i] = temp;
    }
    sort_data(array,MAX);
    total = clock() - start;
    cout << "Bubble sorted " << MAX << " items in: " << total << " cycles" 
         << " (" << (float)total/CLOCKS_PER_SEC << " seconds)" << endl;
    return true;
}
#undef MAX
