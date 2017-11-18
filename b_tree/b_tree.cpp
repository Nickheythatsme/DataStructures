//
// Created by nick on 11/17/2017.
//

#include "b_tree.h"

template<class KEY,class DATA>
b_tree<KEY,DATA>::b_tree()
{
    root = nullptr;
}

template<class KEY,class DATA>
b_tree<KEY,DATA>::b_tree(const b_tree<KEY, DATA> &obj)
{
    //TODO handle dead lock appropriately
    lock_guard<mutex> guard1(obj.t_lock);
    lock_guard<mutex> guard2(this -> t_lock);

    if(obj.root)
        root = new node<KEY,DATA>(*obj.root);
    else
        root = nullptr;
}

template<class KEY,class DATA>
b_tree<KEY,DATA>::~b_tree()
{
    lock_guard<mutex> guard(this -> t_lock);
    if(root)
        root -> clear();
    delete root;
}

template<class KEY,class DATA>
DATA b_tree<KEY,DATA>::lowest()
{
    lock_guard<mutex> guard(this -> t_lock);

    return nullptr;
}

template<class KEY,class DATA>
DATA b_tree<KEY,DATA>::highest()
{
    return nullptr;
}

template<class KEY,class DATA>
DATA *b_tree<KEY,DATA>::sort()
{
    return nullptr;
}

template<class KEY,class DATA>
bool b_tree<KEY,DATA>::exists(KEY &key)
{
    return false;
}

template<class KEY,class DATA>
DATA b_tree<KEY,DATA>::operator[](KEY &key)
{
    return nullptr;
}

