//
// Created by nick on 11/17/2017.
//

#include "b_tree.h"

template<class KEY,class DATA>
int b_tree<KEY,DATA>::insert(const KEY& key, const DATA& data)
{
    lock_guard<mutex> guard2(this -> t_lock);

    datum<KEY,DATA> to_insert(key,data);
    return node<KEY,DATA>::insert(to_insert,root);
}

template<class KEY,class DATA>
int b_tree<KEY,DATA>::insert(const datum<KEY,DATA>& to_insert)
{
    lock_guard<mutex> guard2(this -> t_lock);

    return node<KEY,DATA>::insert(to_insert,root);
}

/* CONSTRUCTOR */
template<class KEY,class DATA>
b_tree<KEY,DATA>::b_tree()
{
    root = new node<KEY,DATA>;
}

/* COPY CONSTRUCTOR */
template<class KEY,class DATA>
b_tree<KEY,DATA>::b_tree(const b_tree<KEY, DATA> &obj)
{
    //TODO handle dead lock appropriately
    lock_guard<mutex> guard1(obj.t_lock);
    lock_guard<mutex> guard2(this -> t_lock);

    root = new node<KEY,DATA>(*obj.root);
}

/* DESTRUCTOR */
template<class KEY,class DATA>
b_tree<KEY,DATA>::~b_tree()
{
    lock_guard<mutex> guard(this -> t_lock);
    root -> clear();
    delete root;
}

template<class KEY,class DATA>
DATA b_tree<KEY,DATA>::lowest() const
{
    return nullptr;
}

template<class KEY,class DATA>
DATA b_tree<KEY,DATA>::highest() const
{
    return nullptr;
}

template<class KEY,class DATA>
DATA *b_tree<KEY,DATA>::sort() const
{
    return nullptr;
}

template<class KEY,class DATA>
bool b_tree<KEY,DATA>::exists(KEY const &key) const
{
    return false;
}

template<class KEY,class DATA>
DATA b_tree<KEY,DATA>::operator[](KEY const &key) const
{
    return nullptr;
}

