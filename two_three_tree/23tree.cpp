#include "23tree.h"

//WRAPPER for the insert function.
template <class T, class N>
bool tree<T>::insert(const T& data)
{
    node<T> * temp = root;
    if( !root -> insert(temp, data) )
        return false;
    root = temp;
    return true;
}


//Display all nodes in the tree.
template <class T>
std::ostream& tree<T>::display_all(std::ostream & out) const
{
    int invoc = 0;
    root -> display_all(out, root, invoc);
    return out;
}

template <class T>
std::ostream& tree<T>::display_ordered(std::ostream & out) const
{
    root -> display_ordered(out, root);
    return out;
}

template <class T>
std::ostream& operator<<(std::ostream & out, const tree<T> & obj)
{
    obj.display_all(out);
    return out;
}

template <class T>
tree<T>& tree<T>::operator=(const tree<T> & obj)
{
    root -> remove_all(root);
    if( obj.root )
    root = new node<T>(*obj.root);
    return *this;
}

//DEFAULT CONSTRUCTOR
template <class T>
tree<T>::tree()
{
    root = new node<T>();
}

//COPY CONSTRUCTOR. This copies all the nodes from another tree into our tree.
template <class T>
tree<T>::tree(const tree<T> & obj)
{
    if( obj.root )
        root = new node<T>(*obj.root);
    else
        root = NULL;
}

//DESCTRUCTOR
template <class T>
tree<T>::~tree()
{
    root -> remove_all(root);
    root = NULL;
}

