//
// Created by Nick Grout on 10/29/17.
//

#include "node.h"
//#include <iostream>

using std::cout;
using std::endl;

/* Data holder functions */
void test_data_handler_basic();
void test_data_handler_split();
void test_sort();
void test_sort_extended();

/* Node functions */
void test_node_basic();
void test_split();
void test_insert_basic();

int main(int argc, char *argv[])
{
    if(argc <= 1) {
        cout << "Usage: b_tree [number] [number] ..." << endl;
        return 1;
    }

    test_insert_basic();

    return 0;
}


/* NODE TESTS */
void test_node_basic()
{
    cout << "Calling test_node_basic" << endl;
    srand(clock());
    int temp = rand() % 10;
    node<int> test_node(temp);

    for(int i = 0; i < MAX_DATA + 1; ++i) {
        temp = rand() % 10;
        cout << "Inserting: " << temp << endl;
        if(!test_node.insert(temp))
            cout << "node is full" << endl;
    }
    test_node.display(cout);
}

//Test insert without splitting but with multiple nodes
void test_insert_basic()
{
    cout << "Testing insert basic" << endl;
    /* Make root */
    node<int> *root = new node<int>(50);
    root -> insert(60);

    /* Make a left */
    node<int> *left = new node<int>(20);

    /* Make a middle */
    node<int> *middle = new node<int>(55);

    /* Make a right */
    node<int> *right = new node<int>(75);
    right -> insert(85);

    /* Connect nodes */
    root -> connect(left,0);
    root -> connect(middle,1);
    root -> connect(right,2);

    /* Display before insertion */
    root -> display(cout);

    root -> insert(10);
    root -> display(cout);

    root -> insert(56);
    root -> display(cout);

    root -> insert(100);
    root -> display(cout);

    return;
}


void test_next_child()
{
    cout << "test_next_child()" << endl;
    srand(clock());
    int temp = rand() % 10;
    node<int> test_node(temp);

    for(int i = 1; i < MAX_DATA + 1; ++i) {
        test_node.display(cout);
        temp = rand() % 10;
        cout << "Inserting: " << temp << endl;
        test_node.insert(temp);
    }
}

void test_split()
{
    cout << "Testing split" << endl;
    node<int> n1(5);
    node<int> n2(0);

    n1.insert(4);
    n1.insert(3);

    n1.connect(&n2,0);

    n1.insert(1);
    n1.insert(2);

    n1.display(cout);
    return;
}


/* DATA HOLDER TESTS  */
void test_data_handler_split()
{
    data_holder<int> test_holder;
    split_holder<int> test_split;
    int temp = 0;
    srand(clock());

    test_split.new_data = 5;
    cout << "Test" << endl;

    for(int i = 0; i < 6; ++i) {
        temp = rand() % 10;
        cout << "Inserting: " << temp << endl;
        cout << "Full? " << test_holder.is_full() << endl;
        if(!test_holder.insert(temp))
            cout << "holder is full" << endl;
    }

    cout << "Splitting: " << endl;
    test_holder.split(test_split);
}

void test_data_handler_basic()
{
    data_holder<int> test_holder;
    int temp = 0;
    srand(clock());

    for(int i = 0; i < 3; ++i) {
        temp = rand() % 10;
        cout << "Inserting: " << i << endl;
        cout << "Full? " << test_holder.is_full() << endl;
        if(!test_holder.insert(temp))
            cout << "holder is full" << endl;
    }
    test_holder.display(cout);
    cout << "Testing where 0 is: "
         << test_holder.compare(0) << endl
         << "Testing where 5 is: "
         << test_holder.compare(5) << endl;
}



void test_sort()
{
    cout << "Test sort" << endl;
    int array[] = {9, 6, 6, 3};
    int len = 4;

    for(int i = 0; i < len; ++i)
        cout << array[i] << ',';
    cout << endl;

    sort(array, len);

    for(int i = 0; i < len; ++i)
        cout << array[i] << ',';
    cout << endl;

    sort(array, len);

    for(int i = 0; i < len; ++i)
        cout << array[i] << ',';
    cout << endl;
    cout << endl;

    test_sort_extended();

}

void test_sort_extended()
{
    cout << "Test sort extended" << endl;
    int array[] = {9, 6, 6, 3};
    int len = 3;
    data_holder<int> holder;

    for(int i = 0; i < len; ++i) {
        holder.insert(array[i]);
        holder.display(cout);
    }

    for(int i = 0; i <= 10; ++i)
        cout << "Comparing " << i << ": " << holder.compare(i) << endl;
}
