#include "node.h"
#include <iostream>

using namespace std;


int main(int argc, char* argv[])
{
    string data("This is a string");
    node* root = new node(data);
    for(int i = 0; i < 1; ++i)
        cout << root -> enqueue(data) << endl;
    for(int i = 0; i < 10 && root; ++i)
        cout << node::dequeue(root) << endl;
    return 0;
}
