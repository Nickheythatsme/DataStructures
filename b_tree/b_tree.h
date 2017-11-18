//
// Created by nick on 11/17/2017.
//

#include "node.h"
#include <mutex>

#ifndef PROJECT_B_TREE_H
#define PROJECT_B_TREE_H

using std::mutex;
using std::lock_guard;

template<class KEY,class DATA>
class b_tree
{
    public:
        b_tree();
        b_tree(const b_tree<KEY,DATA> &obj);
        ~b_tree();
        DATA lowest() const;
        DATA highest() const;
        DATA* sort() const;
        bool exists(KEY const &key) const;
        DATA operator[](KEY const &key) const; //Used for retrieval
        int insert(const KEY& key, const DATA& data);
        int insert(const datum<KEY,DATA>& to_insert);
    private:
        node<KEY,DATA> *root;
        mutex t_lock;
};

#include "b_tree.cpp"

#endif //PROJECT_B_TREE_H

