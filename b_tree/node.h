//
// Created by Nick Grout on 10/29/17.
//
#include "data_holder.h"

#ifdef SENTIMENTANALYSIS_B_TREE_H
#ifndef SENTIMENTANALYSIS_NODE_H
#define SENTIMENTANALYSIS_NODE_H

template<class KEY, class DATA>
class node : public data_holder<KEY, DATA>
{
    public:
        node();
        node(node<KEY, DATA> const &obj);
        explicit node(datum<KEY,DATA> const &obj);
        explicit node(data_holder<KEY, DATA> const &obj);
        ~node();
        /* Insert new data (wrapper),
         * and move root if we get a new root (not wrapper) */
        static int insert(datum<KEY,DATA> const &new_data, node<KEY, DATA> *&root);
        /* Display the whole subtree (wrapper) */
        std::ostream &display(std::ostream &out);
        /* Determine what the next child is based on the data. Returns -1 if something is wrong */
        node<KEY, DATA> *next_child(datum<KEY,DATA> const &new_data);
        /* Remove all nodes in this subtree */
        void clear();
    protected:
        /* Display the whole subtree recursively */
        std::ostream &display(std::ostream &out, size_t tabspace);
        /* Recursive function for inserting new data */
        int insert(struct split_info<KEY, DATA> *&new_struct);
        /* Resolve the split from our children */
        int resolve_split(struct split_info<KEY, DATA> *&in_split);
        /* Split ourselves if we're a leaf (basic split w/o handling children */
        int split_leaf(struct split_info<KEY, DATA> *new_struct);
        /* Split ourselves if we're internal
         * (split_leaf plus additional children handling */
        int split_internal(struct split_info<KEY, DATA> *&new_struct);
        /* Manually connect a new node */
        void connect(node<KEY, DATA> *new_child, short child_index);
        /* Return true if we have no children */
        bool is_leaf() const;
    private:
        node<KEY, DATA> **children; /* Array to hold our children */
};


#include "node.cpp"

#endif //SENTIMENTANALYSIS_NODE_H
#endif //SENTIMENTANALYSIS_B_TREE_H
