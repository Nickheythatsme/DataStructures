//
// Created by Nick Grout on 10/29/17.
//
#include "node.h"

template<class DATA>
std::ostream &node<DATA>::display(std::ostream &out)
{
    return display(out, 0);
}

template<class DATA>
std::ostream &node<DATA>::display(std::ostream &out, size_t tabspace)
{
    for(size_t i = 0; i < tabspace; ++i)
        out << "  ";
    data_holder<DATA>::display(out);

    ++tabspace;
    for(int i = 0; i < MAX_DEGREE; ++i) {
        if(children[i]) {
            out << i << ":" << tabspace;
            children[i]->display(out, tabspace);
        }
    }
    return out;
}

//Static
template<class DATA>
int node<DATA>::insert(DATA const &new_data, node<DATA> *&root)
{
    node<DATA> *new_root;
    split_info<DATA> *new_struct = new split_info<DATA>;
    new_struct->new_data = new_data;

    root->insert(new_struct);

    //Move our old root to the new one if it exists
    if(new_struct->new_right) {
        new_root = new node<DATA>(new_struct->push_up_data);
        new_root->connect(root, 0);
        new_root->connect(new_struct->new_right, 1);
        root = new_root;
    }
    delete new_struct;
    return 1;
}

//Recursively find the spot we're supposed to insert. Insert on the recursive calls,
//then on the return from the calls we test to see if we have an incoming split.
template<class DATA>
int node<DATA>::insert(struct split_info<DATA> *&new_struct)
{
    if(this->is_leaf()) {
        if(this->is_full())
            return this->split_leaf(new_struct);
        else return data_holder<DATA>::add(new_struct->new_data);
    }

    /* Recursive call */
    this->next_child(new_struct->new_data)->insert(new_struct);

    if(new_struct->new_right)
        return this->resolve_split(new_struct);
    return 1;
}

//Split our node for our parent's absorption
template<class DATA>
int node<DATA>::split_leaf(struct split_info<DATA> *new_struct)
{
    new_struct->new_right = new node<DATA>;
    data_holder<DATA>::split(new_struct);

    return 1;
}

template<class DATA>
int node<DATA>::split_internal(struct split_info<DATA> *&new_struct)
{
    int child_index;
    struct split_info<DATA> *our_struct = new split_info<DATA>;
    our_struct->new_data = new_struct->push_up_data;


    /* First part is the same as split leaf */
    this->split_leaf(our_struct);
    /* We need to see where the children
     * will go after we split :( */
    child_index = data_holder<DATA>::compare(new_struct->push_up_data);

    // move the new unconnected node to the new right's leftmost child
    our_struct->new_right->connect(new_struct->new_right, 0);
    // move our children to the new node
    for(int i = child_index + 1, j = 1; i < MAX_DEGREE; ++i, ++j) {
        our_struct->new_right->connect(this->children[i], j);
        this->connect(nullptr, i);
    }


    // Get rid of the old split_info
    delete new_struct;
    new_struct = our_struct;

    return 1;
}

/* Resolve an incoming split. in_split is the incoming struct, our_split
 * is ourselves splitting (only if we need to!) */
template<class DATA>
int node<DATA>::resolve_split(struct split_info<DATA> *&in_split)
{
    int child_index;
    /* Case 1: We have an incoming data and we're NOT full */
    if(!this->is_full()) {

        //Where will the new child go?
        child_index = data_holder<DATA>::compare(in_split->push_up_data);

        /* Shift our children to make room for new child */
        for(int i = MAX_DEGREE - 2; i > child_index; --i)
            children[i + 1] = children[i];

        //Connect new child
        this->connect(in_split->new_right, child_index + 1);

        //Set new_right to null again
        in_split->new_right = nullptr;

        return this->data_holder<DATA>::add(in_split->push_up_data);
    }
    /* Case 2: We have incoming data and we ARE full */
    return this->split_internal(in_split);
}

/* Returns the pointer to the next child, depending on the data */
template<class DATA>
node<DATA> *node<DATA>::next_child(DATA const &new_data)
{
    return children[data_holder<DATA>::compare(new_data)];
}

/* Connect a pointer to a node to our children index */
template<class DATA>
void node<DATA>::connect(node<DATA> *new_child, size_t child_index)
{
    this->children[child_index] = new_child;
}

template<class DATA>
bool node<DATA>::is_leaf() const
{
    /* I could use a for loop but this is pretty quick and avoids unnecessary jumps */
    char accum = false;

    //TODO implement a macro here so we don't have to manually change this
    accum += children[0] == NULL;
    accum += children[1] == NULL;
    accum += children[2] == NULL;
    accum += children[3] == NULL;

    return accum == MAX_DEGREE;
}

template<class DATA>
node<DATA>::node(DATA const &obj) : data_holder<DATA>(obj)
{
    children = new node<DATA> *[MAX_DEGREE];
    for(int i = 0; i < MAX_DEGREE; ++i)
        children[i] = NULL;
}

template<class DATA>
node<DATA>::node(node<DATA> const &obj) : data_holder<DATA>(obj)
{
    children = new node<DATA> *[MAX_DEGREE];
    for(int i = 0; i < MAX_DEGREE; ++i) {
        if(obj.children[i])
            children[i] = new node<DATA>(*obj.children[i]);
        else
            children[i] = NULL;
    }
}

/* Constructor */
template<class DATA>
node<DATA>::node() : data_holder<DATA>()
{
    children = new node<DATA> *[MAX_DEGREE];
    for(int i = 0; i < MAX_DEGREE; ++i)
        children[i] = NULL;
}

/* COPY CONSTRUCTOR */
template<class DATA>
node<DATA>::node(data_holder<DATA> const &obj) : data_holder<DATA>(obj)
{
    children = new node<DATA> *[MAX_DEGREE];
    for(int i = 0; i < MAX_DEGREE; ++i)
        children[i] = NULL;
}

/* DESTRUCTOR */
template<class DATA>
node<DATA>::~node()
{
    delete[] children;
    children = NULL;
}

/* Clears all nodes in this subtree. DOES NOT clear self  */
template<class DATA>
void node<DATA>::clear()
{
    for(int i = 0; i < MAX_DEGREE && children[i]; ++i) {
        children[i]->clear();
        delete children[i];
        children[i] = NULL;
    }
}

