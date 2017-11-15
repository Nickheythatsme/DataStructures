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

void test_insert()
{
    auto *root = new node<int>;
    int temp;
    srand(1);

    for(int i = 0; i < 20; ++i) {
        temp = rand() % MAX;
        cout << i << ") Inserting: " << temp << endl;
        node<int>::insert(temp, root);
        root->display(cout);
        cout << endl << endl;
    }
}

#undef MAX

