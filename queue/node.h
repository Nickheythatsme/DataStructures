#include <stdlib.h>
#include <string>
#include <cassert>


using std::string;
/*
#ifndef QUEUE_NODE_
#define QUEUE_NODE_
*/

class node
{
    public:
        node();
        node(const node& new_data);
        node(const string& new_data);
        ~node();
        /* Wrapper for other add function */
        int enqueue(const string& new_data);
        /* Remove the current node, returns a ptr by ref to the node that takes
         * it's place (or NULL if it doesn't exist) */
        static string dequeue(node*& root);
        /* Clears this node and its subtree */
        int clear(void);
    private:
        /* Recursively place the data into the tree. Returns the number the item
         * is in the tree.
         * Since we're not going to a specified position, just the nearest one
         * that is open, we need a marker to indicate when we're done */
        int add(const string& new_data, int& placed);
        int place_here(const string& new_data, int& placed);

        static node* in_order_successor(node*& obj);
        static node* all_the_way_left(node*& prev, node*& obj);

        node* right;
        node* left;
        string data;

};

//#endif