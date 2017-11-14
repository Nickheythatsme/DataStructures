//
// Created by Nick Grout on 10/22/17.
//
// This holds and handles the data in the node. It handles sorting, splitting,
// insertion, and compares to incoming data points 

#include <cassert>
#include <iostream>

#define MAX_DEGREE 4 
#define MAX_DATA (MAX_DEGREE - 1)

#ifndef SENTIMENTANALYSIS_B_TREE_H
#define SENTIMENTANALYSIS_B_TREE_H

using std::cout;
using std::endl;

template<class DATA>
class data_holder;

template<class DATA>
struct split_holder
{
    DATA new_data;
    DATA push_up_data;
    data_holder<DATA> new_holder;
};

template<class DATA>
int sort(DATA *array, int len);

template<class DATA>
class data_holder
{
    public:
        data_holder();
        data_holder(data_holder<DATA> const &obj);
        explicit data_holder(DATA const &new_data);
        virtual ~data_holder();
        virtual int insert(DATA const &new_data);
        virtual int split(split_holder<DATA> &temp_holder);
        int is_full() const;
        int return_data_count() const;
        /* Test if the to_compare variable is in this array.
         * Returns 1 if the value is in this array, 0 if it is not */
        int find(DATA const &to_compare);
        /* Test to see where this data would be if it was in the array.
         * Returns the index of the first array value which is lower than the test value */
        int compare(DATA const &to_compare);
        /* TODO Remove when not debugging */
        std::ostream &display(std::ostream &out);
    protected:
        void clear_data(bool do_delete = false);
    private:
        //static int sort(DATA* array, int len);
        DATA *data;
        int data_count;
};


#include "data_holder.cpp"

#endif //SENTIMENTANALYSIS_B_TREE_H
