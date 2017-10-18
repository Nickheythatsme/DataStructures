#include "node.h"

node::node()
{
    right = left = NULL;
}

/* Recursively copies the node's subtree.*/
node::node(const node& new_node)
{
    if( new_node.right )
        right = new node(*new_node.right);
    else
        right = NULL;

    if( new_node.left )
        left = new node(*new_node.left);
    else
        left = NULL;

    data = new_node.data;
}

node::node(const string& new_data)
{
    right = left = NULL;
    data = new_data;
}

/* DESTRUCTOR */
node::~node()
{
    left = right = NULL;
}

/* Recursively calls next add to add the node to the queue.
 * We pass by ref because at some point we would like to
 * be able to prioritize items. Returns the node's place in the
 * queue */
int node::add(const string& new_data, int& placed)
{
    if( placed )
        return 0;

    /* We want less instructions in this recursive call. When we need to place
     * the data we can call another function */
    if( !left || !right )
        return this -> place_here(new_data, placed);

    /* Make the recursive call. Return +1 because we're one level lower */
    /* We add 2 because us, left, and right are all taken. */
    return right -> add(new_data, placed) + left -> add(new_data, placed) + 2;
}

/* Place the data into this node. Returns -1 if there's no room */
int node::place_here(const string& new_data, int& placed)
{
    int place_in_queue = 0;
    ++place_in_queue;
    if( !right )
    {
        right = new node(new_data);
        placed = 1;
        return place_in_queue;
    }

    ++place_in_queue;
    if( !left )
    {
        left = new node(new_data);
        placed = 1;
        return place_in_queue;
    }
    return -1;
}

/* Same as add node, only we make a new node and wrap it around the
 * data */
int node::enqueue(const string& new_data)
{
    int temp = 0;
    return this -> add(new_data, temp);
}

/* Remove the current node, returns a ptr by ref to the node that takes
 * it's place (or NULL if it doesn't exist) */
string node::dequeue(node*& root)
{
    /* Get and finish root's replacement */
    string to_return(root -> data);
    node* IOS = node::in_order_successor(root);
    cout << "Root address: " << root << endl;
    if( IOS )
    {
        cout << "IOS address: " << IOS << endl;
        IOS -> right = root -> right;
        IOS -> left = root -> left;
    }
    cout << "Root -> right" << root -> right << endl;
    cout << "Root -> left" << root -> left << endl;
    delete root;
    root = IOS;
    return to_return;
}

node* node::in_order_successor(node*& obj)
{
    if(!obj -> right)
        return obj -> left;
    return node::all_the_way_left(obj -> right, obj -> right);
}

node* node::all_the_way_left(node*& prev, node*& obj)
{
    node* to_return;
    if(!obj -> left)
    {
        to_return = obj;
        prev -> left = obj -> right;
        to_return -> right = NULL;
        return to_return;
    }
    return node::all_the_way_left(obj, obj -> left);
}

