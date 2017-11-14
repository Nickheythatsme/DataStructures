//
// Created by Nick Grout on 10/29/17.
//
#include "node.h"

template<class DATA>
std::ostream& node<DATA>::display(std::ostream& out)
{
    out << "Max degree: " << MAX_DEGREE << endl;
    return display(out,0);
}

template<class DATA>
std::ostream& node<DATA>::display(std::ostream& out, size_t tabspace)
{
    for(size_t i = 0; i < tabspace; ++i)
        out << "  ";
    data_holder<DATA>::display(out);

    ++tabspace;
    for(int i = 0; i < MAX_DEGREE; ++i)
    {
        if( children[i] )
            children[i] -> display(out, tabspace);
    }
    return out;
}

//Wrapper for insert function. Returns the result of the non-wrapper insert()
//function
template<class DATA>
int node<DATA>::insert(DATA const &new_data)
{
    split_node<DATA> new_struct;
    new_struct.new_data = new_data;

    return this -> insert(new_struct);
}

//Recursively find the spot we're suppossed to insert. Insert on the recursive calls,
//then on the return from the calls we test to see if we have an incoming split.
template<class DATA>
int node<DATA>::insert(struct split_node<DATA> &new_struct)
{
    if(this -> is_leaf())
    {
        if(this -> is_full())
            return this -> data_holder<DATA>::split(new_struct);
        return data_holder<DATA>::insert(new_struct.new_data);
    }


    /* Recursive call */
    this -> next_child(new_struct.new_data)->insert(new_struct);

    //TODO finish split
    if(new_struct.incoming_split)
        this -> absorb(new_struct);
    return 1;
}

//Absorb a split struct into our node. If we're also full then we absorb and
//split again, returning the same split struct and giving it to our parent node
template<class DATA>
int node<DATA>::absorb(struct split_node<DATA> &incoming)
{

    //Case 1: We get an incoming datum and data_holder and we're NOT full
    if(!this -> is_full())
    {
        this -> children[ data_holder<DATA>::compare(incoming.push_up_data) ] =
            new node<DATA>(incoming.new_holder);
        this -> data_holder<DATA>::insert(incoming.push_up_data);
        return 1;
    }

    //Case 2: We get an incoming datum and data_holder and we're full
    return this -> split(incoming);
}

template<class DATA>
int node<DATA>::split(struct split_node<DATA> &incoming)
{
    /* Split ourselves */
    split_node<DATA> new_struct;
    this -> data_holder<DATA>::split(new_struct);

    /* Create our new right and give it our right data */
    node<DATA> *new_right = new node<DATA>(new_struct.new_holder);

    /* TODO we need to move our children to the new node */
    /* Move some of our children to new node */
    for(int i = (MAX_DEGREE / 2)+1; i < MAX_DEGREE; ++i)
    {
        new_right -> connect(this -> children[i], i);
        this -> connect(nullptr, i);
    }

    return 1;
}

/* Returns the pointer to the next child, depending on the data */
template<class DATA>
node<DATA> *node<DATA>::next_child(DATA const &new_data)
{
    int child_index = data_holder<DATA>::compare(new_data);
    if(child_index < 0)
        return NULL;
    return children[child_index];
}

/* Connect a pointer to a node to our children index */
template<class DATA>
int node<DATA>::connect(node<DATA> *new_child, int child_index)
{
    if(children[child_index]) return 0;
    children[child_index] = new_child;
    return 1;
}

template<class DATA>
int node<DATA>::is_leaf() const
{
    for(int i = 0; i < MAX_DEGREE; ++i)
        if(children[i])
            return false;
    return true;
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

template<class DATA>
split_node<DATA>::split_node()
{
    new_right = nullptr;
}

template<class DATA>
split_node<DATA>::~split_node()
{
    if( new_right ) delete new_right;
    new_right = nullptr;
}
