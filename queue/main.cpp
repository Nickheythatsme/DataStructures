#include "node.h"
#include <iostream>

using namespace std;


int main(int argc, char* argv[])
{
    string data("This is a string");
    string return_data;
    node* root = new node(data);
    for(int i = 0; i < 1; ++i)
        cout << root -> enqueue(data) << endl;
    for(int i = 0; i < 10 && root; ++i)
    {
        node::dequeue(root,return_data);
        cout << return_data << endl;
    }
    return 0;
}
