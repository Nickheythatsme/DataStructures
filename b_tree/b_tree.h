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
        DATA lowest();
        DATA highest();
        DATA* sort();
        bool exists(KEY &key);
        DATA operator[](KEY &key); //Used for retrieval
    private:
        node<KEY,DATA> *root;
        mutex t_lock;
};

#endif //PROJECT_B_TREE_H

