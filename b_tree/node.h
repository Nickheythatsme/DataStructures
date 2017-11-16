//
// Created by Nick Grout on 10/29/17.
//
#include "data_holder.h"


#ifdef SENTIMENTANALYSIS_B_TREE_H
#ifndef SENTIMENTANALYSIS_NODE_H
#define SENTIMENTANALYSIS_NODE_H

template<class DATA>
class node : public data_holder<DATA>
{
    public:
        node();
        node(node<DATA> const &obj);
        explicit node(DATA const &obj);
        explicit node(data_holder<DATA> const &obj);
        ~node();
        /* Insert new data (wrapper), 
         * and move root if we get a new root (not wrapper) */
        static int insert(DATA const &new_data, node<DATA> *&root);
        /* Display the whole subtree (wrapper) */
        std::ostream &display(std::ostream &out);
        void clear();
    protected:
        /* Determine what the next child is based on the data. Returns -1 if 
         * something is wrong... */
        node<DATA> *next_child(DATA const &new_data);
        /* Display the whole subtree recursively */
        std::ostream &display(std::ostream &out, size_t tabspace);
        /* Recusive function for inserting new data */
        int insert(struct split_info<DATA> *&new_struct);
        /* Resolve the split from our children */
        int resolve_split(struct split_info<DATA> *&in_split);
        /* Split ourselves if we're a leaf (basic split w/o handling children */
        int split_leaf(struct split_info<DATA> *new_struct);
        /* Split ourselves if we're internal
         * (split_leaf plus additional children handling */
        int split_internal(struct split_info<DATA> *&new_struct);
        /* Manually connect a new node */
        void connect(node<DATA> *new_child, size_t child_index);
        /* Return true if we have no children */
        bool is_leaf() const;
    private:
        node<DATA> **children; /* Array to hold our children */
};


#include "node.cpp"

#endif //SENTIMENTANALYSIS_NODE_H
#endif
