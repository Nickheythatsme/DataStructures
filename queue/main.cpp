#include "node.h"
#include <iostream>

using namespace std;


int main(int argc, char* argv[])
{
    string data("This is a string");
    node* root = new node(data);
    for(int i = 0; i < 15; ++i)
        cout << root -> enqueue(data) << endl;
    while( root )
        cout << node::dequeue(root) << endl;
    return 0;
}
