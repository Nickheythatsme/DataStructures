//
// Created by Nick Grout on 10/29/17.
//

#include "node.h"
//#include <iostream>
#include <ctime>

using std::cout;
using std::endl;

/* Node functions */
void test_insert();

int main(int argc, char *argv[])
{
    //test_insert_basic();
    test_insert();

    return 0;
}


/* NODE TESTS */
#define MAX 100
#define LEN 20

void test_insert()
{
    auto *root = new node<int>;
    int data[] = {83,86,77,15,93,35,86,92,49,21,27,90,59,63,26,40,26,72,20,20};
    srand(1);

    for(int i = 0; i < LEN; ++i) {
        cout << data[i] << ", ";
    }
    cout << endl;

    for(int i = 0; i < LEN; ++i) {
        cout << i << ") Inserting: " << data[i] << endl;
        node<int>::insert(data[i], root);
        root->display(cout);
        cout << endl << endl;
    }
}

#undef LEN
#undef MAX

