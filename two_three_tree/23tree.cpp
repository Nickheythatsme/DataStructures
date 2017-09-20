#include "23tree.h"

//WRAPPER for the insert function.
template <class T, class N>
bool tree<T,N>::insert(const T& data)
{
    N<T> * temp = root;
    if( !root -> insert(temp, data) )
        return false;
    root = temp;
    return true;
}


//Display all nodes in the tree.
template <class T, class N>
std::ostream& tree<T,N>::display_all(std::ostream & out) const
{
    int invoc = 0;
    root -> display_all(out, root, invoc);
    return out;
}

template <class T, class N>
std::ostream& tree<T,N>::display_ordered(std::ostream & out) const
{
    root -> display_ordered(out, root);
    return out;
}

template <class T, class N>
std::ostream& operator<<(std::ostream & out, const tree<T,N> & obj)
{
    obj.display_all(out);
    return out;
}

template <class T, class N>
tree<T,N>& tree<T,N>::operator=(const tree<T,N> & obj)
{
    root -> remove_all(root);
    if( obj.root )
    root = new N<T>(*obj.root);
    return *this;
}

//DEFAULT CONSTRUCTOR
template <class T, class N>
tree<T,N>::tree()
{
    root = new N<T>();
}

//COPY CONSTRUCTOR. This copies all the nodes from another tree into our tree.
template <class T, class N>
tree<T,N>::tree(const tree<T,N> & obj)
{
    if( obj.root )
        root = new N<T>(*obj.root);
    else
        root = NULL;
}

//DESCTRUCTOR
template <class T, class N>
tree<T,N>::~tree()
{
    root -> remove_all(root);
    root = NULL;
}

