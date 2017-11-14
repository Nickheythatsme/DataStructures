//
// Created by Nick Grout on 10/29/17.
//
#include "data_holder.h"


#ifdef SENTIMENTANALYSIS_B_TREE_H
#ifndef SENTIMENTANALYSIS_NODE_H
#define SENTIMENTANALYSIS_NODE_H
template<class DATA>
class node;

template<class DATA>
struct split_node : public split_holder<DATA>
{
    split_node();
    ~split_node();
    node<DATA>* new_right;//TODO use this for splitting and transferring children
    char incoming_split; /*True if our child has split and we have data to absorb */
};


template<class DATA>
class node : public data_holder<DATA>
{
    public:
        node() = delete;
        node(node<DATA> const &obj);
        explicit node(DATA const &obj);
        explicit node(data_holder<DATA> const &obj);
        ~node();
        int insert(DATA const &new_data);
        int insert(DATA const &new_data, node<DATA>* new_root);
        std::ostream& display(std::ostream& out);
    //protected:
        node<DATA> *next_child(DATA const &new_data);
        std::ostream& display(std::ostream& out, size_t tabspace);
        int insert(struct split_node<DATA> &new_struct);
        int resolve_split(struct split_node<DATA> &in_split);
        int split_leaf(struct split_node<DATA> &new_struct);
        void connect(node<DATA> *new_child, int child_index);
        void clear();
        bool is_leaf() const;
    private:
        node<DATA> **children;
};


#include "node.cpp"

#endif //SENTIMENTANALYSIS_NODE_H
#endif
