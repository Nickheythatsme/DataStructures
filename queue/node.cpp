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

bool node::dequeue(node*& root, string& to_return)
{
    node* IOS = root -> in_order_successor();
    to_return = root -> data;

    cout << "Root: " << root << endl
         << "IOS:  " << IOS << endl;

    if(IOS && IOS != root)
    {
        IOS -> right = root -> right;
        IOS -> left = root -> left;
        delete root;
        root = IOS;
    }
    else if(IOS == root)
    {
        delete root;
        root = NULL;
    }
    return true;
}

node* node::in_order_successor(void)
{
    if(!right)
        return left;
    return right -> all_the_way_left(this);
}

node* node::all_the_way_left(node* prev)
{
    if(!left)
    {
        prev -> left = right;
        right = NULL;
        return this;
    }
    return left -> all_the_way_left(this);
}

std::ostream& node::display(std::ostream& out)
{
    int tabspace = 0;
    return this -> display(out, tabspace);
}

std::ostream& node::display(std::ostream& out, int tabspace)
{
    for(int i = 0; i < tabspace; ++i)
        cout << "--";
    out << data << endl;
    if(right)
        right -> display(out, tabspace+1);
    if(left)
        left -> display(out, tabspace+1);
    return out;
}
