#include "node.h"
#include <iostream>

using namespace std;


int main(int argc, char* argv[])
{
    char temp = 'b';
    string data = "a";
    string return_data;
    node* root = new node(data);

    for(int i = 0; i < 10; ++i)
    {
        data = temp + i;
        cout << root -> enqueue(data) << endl;
    }
    root -> display(cout);
    /*
    for(int i = 0; i < 10 && root; ++i)
    {
        node::dequeue(root,return_data);
        *root;
        cout << return_data << endl;
    }
    */
    return 0;
}
