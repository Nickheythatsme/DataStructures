//
// Created by nick on 11/17/2017.
//

#include "../b_tree/datum.h"

#ifndef PROJECT_NODE_H
#define PROJECT_NODE_H


template<class KEY,class DATA>
class node
{
    public:
        node() = delete;
        node(const datum<KEY,DATA> &obj);
        ~node();
        int insert(datum<KEY,DATA> &obj);
        static int exists(const KEY &key, const node<KEY,DATA> *root);
    private:
        int insert(datum<KEY,DATA> &obj, node<KEY,DATA> *&root);
        node<KEY,DATA> *right;
        node<KEY,DATA> *left;
        datum<KEY,DATA> data;
};

#include "node.cpp"

#endif //PROJECT_NODE_H
