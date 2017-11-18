//
// Created by Nick Grout on 10/22/17.
//
// This holds and handles the data in the node. It handles sorting, splitting,
// insertion, and compares to incoming data points 

#include <iostream>
//TODO incorporate datum class
#include "datum.h"

#define MAX_DEGREE 4
#define MAX_DATA (MAX_DEGREE - 1)

#ifndef SENTIMENTANALYSIS_B_TREE_H
#define SENTIMENTANALYSIS_B_TREE_H


/* Forward declaration */
template<class KEY, class DATA>
class node;

/* struct used for splitting and inserting data. */
template<class KEY, class DATA>
struct split_info
{
    split_info();
    ~split_info(); /* We do NOT delete new_right if it exists. Other nodes will have taken it and will delete it on their own */
    datum<KEY,DATA> new_data; /* Data incoming from the insert. Exists whether there is a split or not */
    datum<KEY,DATA> push_up_data; /* Data that is pushed up after a split */
    node<KEY, DATA> *new_right; /* The new right node */
};

template<class KEY, class DATA>
int sort(DATA *array, short len);//Bubble sort the array.

template<class KEY, class DATA>
class data_holder
{
    protected:
        data_holder();
        data_holder(data_holder<KEY, DATA> const &obj);
        explicit data_holder(datum<KEY,DATA> const &new_data);
        virtual ~data_holder();
        virtual int add(datum<KEY,DATA> const &new_data);
        /* Split ourselves and sort out left, middle, and right data */
        virtual int split(split_info<KEY, DATA> *temp_holder);
        int is_full() const;
        int return_data_count() const;
        /* Test if the to_compare variable is in this array.
         * returns false if DNE, and true if it does exist. Will copy data into to_return */
        bool get(KEY const &to_compare, DATA &to_return) const;
        /* Test if the to_compare variable is in this array.
         * Returns true if it does, false if it doesn't */
        bool exists(KEY const &to_compare) const;
        /* Test to see where this data would be if it was in the array.
         * Returns the index of the first array value which is lower than the test value */
        int compare(datum<KEY,DATA> const &to_compare) const;
        void clear_data();//Sets data_count to 0
    private:
        datum<KEY,DATA> *data;
        short data_count;
};


#include "data_holder.cpp"

#endif //SENTIMENTANALYSIS_B_TREE_H
