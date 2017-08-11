#include "23tree.h"

//Wrapper for the insert
template<class T>
bool node<T>::insert(node *& root, const T& data)
{
    T temp_data;
    node<T> * right = NULL;
    node<T> * left = NULL;
    node<T> * temp_root = NULL;

    if( !root -> insert( data, root, temp_data, left, right) )
        return false;

    if( left || right )
    {
        temp_root = new node<T>(temp_data);
        temp_root -> connect(left, 0);
        temp_root -> connect(right, 2);
        root = temp_root;
    }

    return true;
}

//Recursively insert the data into the tree
template<class T>
bool node<T>::insert(const T& data, node<T> * root, T& middle_data, node<T> *& new_left, node<T> *& new_right)
{
    if( !root ) return false;

    //Recurisve call
    insert(data, root -> next(data), middle_data, new_left, new_right);

    //If the recursive call had a push up event, we need to either take that
    //data or split ourselves.
    if( new_left || new_right )
        root -> absorb( data, middle_data, new_left, new_right );

    //If we're a leaf and we're NOT full we can insert.
    if( root -> is_leaf() && !root -> is_full() )
        return root -> insert_here(data);

    //If we're a leaf and we're full we need to split.
    if( root -> is_leaf() && root -> is_full() )
    {
        root -> split(data, middle_data, new_left, new_right);
        return true;
    }

    return true;
}

//Node absorb function.
template<class T>
bool node<T>::absorb(const T& data, T& middle_data, node<T> *& new_left, node<T> *& new_right)
{
    int child_index = -1;
    if( !is_full() )
    {
        insert_here(middle_data);

        child_index = which_child(data);
        if( child_index == 2 )
        {
            connect(new_left, 1);
            connect(new_right, 2);
        }
        if( child_index == 0 )
        {
            connect(new_left,0);
            connect(new_right,1);
        }

        new_left = new_right = NULL;
    }

    else //this node is full.
    {
        node<T> * temp_right = new_right;
        node<T> * temp_left = new_left;
        int temp_middle = middle_data;
        new_right = new_left = NULL;

        split(temp_middle, middle_data, new_left, new_right);

        new_left -> connect(child[0], 0);
        new_left -> connect(child[1], 2);
        new_left -> connect(NULL,1);

        new_right -> connect(temp_left, 0);
        new_right -> connect(temp_right, 2);
        new_right -> connect(NULL,1);
    }
    return true;
}

//This is the split function. It returns a new node, the middle data, and this
//node all in order.
template <class T>
bool node<T>::split(const T& new_data, T& middle_data, node<T> *& new_left, node<T> *& new_right)
{
    T* temp_array = new T[3];
    int i = 0;
    for(;i < 2; ++i)
        temp_array[i] = data[i];
    temp_array[i] = new_data;
    sort_data(temp_array, 3);

    middle_data = temp_array[1];
    new_left = new node<T>(temp_array[0]);
    new_right = this;

    delete data;
    data = new T[2];
    data[0] = temp_array[2];
    data_count = 1;

    delete temp_array;
    temp_array = NULL;

    return true;
}

//ostream Extraction operator implemented here.
template <class T>
std::ostream& operator<<(std::ostream & out, const node<T> & obj)
{
    int i = 0;
    out << '(';
    for(; i < obj.data_count && i < 2; ++i)
    {
        if( i ) 
            out << ",";
        out << obj.data[i];
    }
    out << ')';
    return out;
}

template <class T>
std::ostream& node<T>::display_all(std::ostream & out, const node<T> * root, int & invoc) const
{
    if( !root ) return out;

    for(int i = 0; i < invoc; ++i)
        out << "  ";
    out << *root << std::endl;
    ++invoc;

    for(int i = 0; i < 3; ++i)
        display_all( out, root -> child[i], invoc );
    --invoc;

    return out;
}

//Display all data in this subtree in sorted order.
template <class T>
std::ostream& node<T>::display_ordered(std::ostream & out, const node<T> * root) const
{
    if(!root) return out;
    if( root -> is_leaf() )
    {
        out << root -> data[0] << ", ";
        if( root -> data_count >= 2)
            out << root -> data[1] << ", ";
        return out;
    }

    display_ordered(out, root -> next_man(0));
    out << root -> data[0] << ", ";
    display_ordered(out, root -> next_man(1));
    if( root -> data_count >= 2)
        out << root -> data[1] << ", ";
    display_ordered(out, root -> next_man(2));

    return out;
}

//This function inserts new data into the node. It returns false if it's full.
template <class T>
bool node<T>::insert_here(const T& new_data)
{
    switch( data_count )
    {
        case 0:
            data[0] = new_data;
            ++data_count;
            break;
        case 1: //If data_count == 1 then we need to insert into the other spot
            data[1] = new_data;
            ++data_count;
            sort_data( data, 2 );//Sort the data because now we have two datum
            break;
        default: //If data_count == 2 then this is a full node.
            return false;
    }
    return true;
}

//Returns the number of data points with the max number of data. It returns true
//if it is full, and false it is not full.
template <class T>
bool node<T>::is_full(void) const
{
    return (data_count >= 2);
}

//Does this node have children? It will return true if it does not have children
//and false if it does have children.
template <class T>
bool node<T>::is_leaf(void) const
{
    for(int i = 0; i < 3; ++i)
        if( child[i] ) return false;
    return true;
}

//Traverse manually to the next child.
template <class T>
node<T>* node<T>::next_man(int child_index) const
{
    return child[child_index];
}

//Returns the index of the next child based on the data.
template <class T>
int node<T>::which_child(const T& obj) const
{
    if( is_leaf() ) return -1;

    switch( data_count )
    {
        case 1:
            if( obj > data[0] )
                return 2;
            if( obj <= data[0] )
                return 0;
        case 2:
            if( obj > data[1] )
                return 2;
            if( obj <= data[0] )
                return 0;
            else
                return 1;
    }
    return -1;
}

//Traverse based on the data.
template <class T>
node<T>* node<T>::next(const T& obj) const
{
    //IF there are no children we can return NULL. Since this is pass pointer
    //by value anyway it won't matter.
    if( is_leaf() ) return NULL;

    switch( data_count )
    {
        case 1:
            if( obj > data[0] )
                return child[2];
            if( obj <= data[0] )
                return child[0];
        case 2:
            if( obj > data[1] )
                return child[2];
            if( obj <= data[0] )
                return child[0];
            else
                return child[1];
    }
    return NULL;
}

//This function connects a node to the indicated child. It will do this whether
//there is a node alreayd there, or even if new_child is NULL. It doesn't really
//check for anything.
template <class T>
bool node<T>::connect(node<T> * new_child, int child_index)
{
    child[child_index] = new_child;
    return true;
}


//DEFAULT CONSTRUCTOR
template <class T>
node<T>::node()
{
    data_count = 0;
    data = new T[2];

    child = new node<T>*[3];
    for(int i = 0; i < 3; ++i)
        child[i] = NULL;
}

//COPY CONSTRUCTOR. This copy constructor DOES copy children.
template <class T>
node<T>::node(const node<T> & obj)
{
    node<T>* temp = NULL;
    data_count = obj.data_count;

    data = new T[2];
    for(int i = 0; i < 2; ++i)
        data[i] = obj.data[i];

    child = new node<T>*[3];
    for(int i = 0; i < 3; ++i)
        if( obj.child[i] )
        {
            temp = new node( *obj.child[i] );
            child[i] = temp;
        }
}

//CONSTRUCTOR. This constructor takes one datum and copies it to the node.
//This is useful for splitting nodes.
template <class T>
node<T>::node(const T& obj)
{
    data_count = 1;

    data = new T[2];
    data[0] = obj;

    child = new node<T>*[3];
    for(int i = 0; i < 3; ++i)
        child[i] = NULL;
}

//DESTRUCTOR. This destructor only deletes one node, not the children of this
//node.
template <class T>
node<T>::~node()
{
    if( data )
    {
        delete [] data;
        data = NULL;
    }

    if( child )
    {
        delete child;
        child = NULL;
    }
}

//Removes all nodes in this subtree.
template <class T>
void node<T>::remove_all(node<T> *& root)
{
    if( !root ) return;
    for(int i = 0; i < 3; ++i)
    {
        if( root -> child[i] )
            remove_all( root -> child[i] );
    }
    delete root;
    root = NULL;
    return;
}



//SORTING functions
//Lazy sort. It works though and the data sets are very small.
template <class T>
bool sort_data(T* data, int len)
{
    //Place holders
    int i = 1;

    //Temp holder
    T prev;

    while( !sorted(data, len) )
    {
        if( data[i-1] > data[i] )
        {
            prev = data[i];
            data[i] = data[i-1];
            data[i-1] = prev;
        }
        ++i %= len;
    }

    return true;
}

//Test if the array is sorted.
template <class T>
bool sorted(T* data, int len)
{
    for( int i = 1; i < len; ++i)
    {
        if( data[i-1] > data[i] )
            return false;
    }
    return true;
}
