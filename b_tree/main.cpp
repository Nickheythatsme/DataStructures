//
// Created by Nick Grout on 10/29/17.
//

#include "node.h"
#include <ctime>
#include <random>
#include <cstring>
//#include <iostream>

using std::cout;
using std::endl;

//TODO remove
void temp_test();

/* Node functions */
void test_insert_planned();
void test_insert_rand();

int main(int argc, char *argv[])
{
    cout << "sizeof node: " << sizeof(node<int>) << endl;
    if( argc > 1 && !strncmp(argv[1],"--rand",6) )
        test_insert_rand();
    else
        test_insert_planned();

    return 0;
}


/* NODE TESTS */

#define MAX 100
#define LEN 1000

void test_insert_rand()
{
    auto *root = new node<int>;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,MAX);

    for(int i = 0; i < LEN; ++i)
        node<int>::insert(distribution(generator), root);
    root->display(cout);

    root -> clear();
    delete root;
}

#undef LEN
#undef MAX

#define MAX 100
#define LEN 11
void test_insert_planned()
{
    auto *root = new node<int>;
    int data[] = {100,90,110,80,120,70,130,60,140,50,150};

    for(int i = 0; i < LEN; ++i) {
        cout << i+1 << ") Inserting: " << data[i] << endl;
        node<int>::insert(data[i], root);
        root->display(cout);
        cout << endl << endl;
    }
    root -> clear();
    delete root;
}

#undef LEN
#undef MAX

