//
// Created by nick on 11/17/2017.
//

#include "node.h"

template<class KEY,class DATA>
node<KEY,DATA>::node(const datum<KEY,DATA> &obj) : data(obj)
{
    left = right = NULL;
}

template<class KEY,class DATA>
node<KEY,DATA>::~node()
{
    if( right )
        delete right;
    if( left )
        delete left;
};

template<class KEY,class DATA>
int node<KEY,DATA>::insert(datum<KEY,DATA> &obj)
{
    if( this -> data <= obj )
        return insert(obj, this -> right);
    else
        return insert(obj, this -> left);
}

template<class KEY,class DATA>
int node<KEY,DATA>::insert(datum<KEY,DATA> &obj, node<KEY,DATA> *&root)
{
    if(!root)
    {
        root = new node<KEY,DATA>(obj);
        return 1;
    }
    if( root -> data <= obj )
        return insert(obj, root -> right);
    else
        return insert(obj, root -> left);
}

template<class KEY,class DATA>
int node<KEY,DATA>::exists(const KEY &key, const node<KEY,DATA> *root)
{
    if(!root) return 0;

    if( root -> data <= key )
        return exists(key, root -> right);
    else
        return exists(key, root -> left);
}
