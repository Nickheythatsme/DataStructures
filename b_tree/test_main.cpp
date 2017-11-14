//
// Created by Nick Grout on 10/29/17.
//

#include "node.h"
//#include <iostream>

using std::cout;
using std::endl;

/* Node functions */
void test_node_basic();
void test_insert_basic();
void test_next_child();

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

    root -> insert(15);
    root -> display(cout);

    root -> insert(18);
    root -> display(cout);

    root -> insert(18);
    root -> display(cout);

    root -> insert(18);
    root -> display(cout);

    root -> clear();
    delete root;

    root = left = middle = right = NULL;

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


