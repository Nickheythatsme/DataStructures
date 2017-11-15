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
        {
            out << i << ": ";
            children[i] -> display(out, tabspace);
        }
    }
    return out;
}

template<class DATA>
int node<DATA>::insert(DATA const &new_data, node<DATA>*& root)
{
    //TODO implement for when we have a tree (wrapper) class
    return 1;
}

//Wrapper for insert function. Returns the result of the non-wrapper insert()
//function
template<class DATA>
int node<DATA>::insert(DATA const &new_data)
{
    split_info<DATA> new_struct;
    new_struct.new_data = new_data;

    return this -> insert(new_struct);
}

//Recursively find the spot we're suppossed to insert. Insert on the recursive calls,
//then on the return from the calls we test to see if we have an incoming split.
template<class DATA>
int node<DATA>::insert(struct split_info<DATA> &new_struct)
{
    if(this -> is_leaf())
    {
        if(this -> is_full())
            return this -> split_leaf(new_struct);
        else return data_holder<DATA>::insert(new_struct.new_data);
    }


    /* Recursive call */
    this -> next_child(new_struct.new_data) -> insert(new_struct);

    //TODO finish split
    if(new_struct.new_right)
        return this -> resolve_split(new_struct);
    return 1;
}

//OVERRIDE
//Split our node for our parent's absorption
template<class DATA>
int node<DATA>::split_leaf(struct split_info<DATA> &new_struct)
{
    new_struct.new_right = new node<DATA>;
    data_holder<DATA>::split(new_struct);

    return 1;
}

template<class DATA>
int node<DATA>::split_internal(struct split_info<DATA> &new_struct)
{
    /* Save the child index */
    int child_index = data_holder<DATA>::compare(new_struct.push_up_data);
    struct split_info<DATA> *our_struct = new split_info<DATA>;
    our_struct -> new_data = new_struct.push_up_data;

    /* First part is the same as split leaf */
    cout << "Self: " << endl;
    this -> display(cout);
    this -> split_leaf(*our_struct);
    cout << "Self: " << endl;
    this -> display(cout);

    /*
    // move our children to the new node
    cout << "Child index: " << child_index << endl;
    for(int i = child_index, j = 0; i < MAX_DEGREE; ++i, ++j)
        new_struct.new_right -> connect(this -> children[i],j);
    */

    cout << "New right: " << endl;
    new_struct.new_right -> display(cout);

    cout << "Self: " << endl;
    this -> display(cout);

    return 1;
}

/* Resolve an incoming split. in_split is the incoming struct, our_split
 * is ourselves splitting (only if we need to!)
 */
template<class DATA>
int node<DATA>::resolve_split(struct split_info<DATA> &in_split)
{
    split_info<DATA> our_split; // We may need to split again 
    int child_index;
    /* Case 1: We have an incoming data and we're NOT full */
    if( !this -> is_full() )
    {
        /* Shift our children to make room for new child */

        //Where will the new child go?
        child_index = data_holder<DATA>::compare(in_split.push_up_data);

        //Shifting 
        for(int i = MAX_DEGREE - 2; i > child_index; --i)
        {
            std::cout << "child: " << i << std::endl;
            children[i+1] = children[i];
        }

        //Connect new child
        this -> connect(in_split.new_right, child_index+1);

        //Set new_right to null again
        in_split.new_right = nullptr;

        return this -> data_holder<DATA>::insert(in_split.push_up_data);
    }
    /* Case 2: We have incoming data and we ARE full */
    else
    {
        return this -> split_internal(in_split);
    }


    return 1;
}






/* Returns the pointer to the next child, depending on the data */
template<class DATA>
node<DATA> *node<DATA>::next_child(DATA const &new_data)
{
    return children[data_holder<DATA>::compare(new_data)];
}

/* Connect a pointer to a node to our children index */
template<class DATA>
void node<DATA>::connect(node<DATA> *new_child, int child_index)
{
    this -> children[child_index] = new_child;
}

template<class DATA>
bool node<DATA>::is_leaf() const
{
    /* I could use a for loop but this is pretty quick and avoids unnecessary jumps */
    char accum = false;

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

/* Clears all nodes in this subtree */
template<class DATA>
void node<DATA>::clear()
{
    for(int i = 0; i < MAX_DEGREE && children[i]; ++i)
    {
        children[i] -> clear();
        delete children[i];
        children[i] = NULL;
    }
}

