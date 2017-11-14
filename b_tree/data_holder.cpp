// Created by Nick Grout on 10/22/17.
//
// This holds and handles the data in the node. It handles sorting, splitting,
// insertion, and compares to incoming data points 
//

#include "data_holder.h"

/* CONSTRUCTOR */
template<class DATA>
data_holder<DATA>::data_holder()
{
    data = new DATA[MAX_DATA];
    data_count = 0;
}

/* CONSTRUCTOR */
template<class DATA>
data_holder<DATA>::data_holder(DATA const &new_data)
{
    data = new DATA[MAX_DATA];
    data_count = 1;
    data[0] = new_data;
}

/* COPY CONSTRUCTOR */
template<class DATA>
data_holder<DATA>::data_holder(data_holder<DATA> const &obj)
{
    data_count = obj.data_count;
    data = new DATA[MAX_DATA];
    for(int i = 0; i < data_count; ++i)
        data[i] = obj.data[i];
}

/* DESTRUCTOR */
template<class DATA>
data_holder<DATA>::~data_holder()
{
    delete[] data;
    data = NULL;
}

/* Split this node */
//TODO finish split function. We need to finish making the new data_handler object */
template<class DATA>
int data_holder<DATA>::split(split_holder<DATA> &temp_holder)
{
    int i = 0;
    int middle_item = 0;
    int last_item = MAX_DATA + 1; //index of the last item in the new array

    /* Create and sort a new array with ALL data */
    DATA *new_array = new DATA[last_item];
    for(; i < MAX_DATA; ++i)
        new_array[i] = data[i];
    new_array[MAX_DATA] = temp_holder.new_data; //Add the last datum
    sort(new_array, last_item);

    /* Find the middle data item */
    middle_item = MAX_DATA / 2;
    temp_holder.push_up_data = new_array[middle_item];

    /* Get the right side of the array */
    for(i = middle_item + 1; i < last_item; ++i)
        temp_holder.new_holder.insert(new_array[i]);

    /* Get the left side of the array */
    this->clear_data(false);
    for(i = 0; i < middle_item; ++i)
        this->insert(new_array[i]);


    //TODO remove when not testing
    for(i = 0; i < last_item; ++i)
        std::cout << new_array[i] << ", ";
    std::cout << std::endl;
    cout << "left: ";
    this->display(std::cout);
    std::cout << "Middle: " << new_array[middle_item] << std::endl;
    cout << "right: ";
    temp_holder.new_holder.display(std::cout);
    //End removal

    return 1;
}

/* Clear the array and remake an empty one */
//TODO Check for cases where we need to delete the array, or if we can just set data_count == 0
/* This function only needs to be called when the DATA type does not have an assignment operator (Which many classes don't)*/
template<class DATA>
void data_holder<DATA>::clear_data(bool do_delete)
{
    data_count = 0;
    if(!do_delete)
        return;
    delete[] data;
    data = new DATA[MAX_DATA];
    return;
}

/* Return how much room is left */
template<class DATA>
int data_holder<DATA>::is_full() const
{
    return data_count >= MAX_DATA;
}

/* Return the number of data items in this array */
template<class DATA>
int data_holder<DATA>::return_data_count() const
{
    return data_count;
}

/* Insert a new data item. Returns 0 if we're full */
template<class DATA>
int data_holder<DATA>::insert(DATA const &new_data)
{
    if(data_count >= MAX_DATA) return 0;
    data[data_count] = new_data;
    sort(data, ++data_count);
    return 1;
}

/* Used for debugging only */
template<class DATA>
std::ostream &data_holder<DATA>::display(std::ostream &out)
{
    for(int i = 0; i < data_count; ++i)
        out << data[i] << ", ";
    out << endl;
    return out;
}

/* Test to see if data is in this node. Returns 1 if is is, 0 if it is not */
template<class DATA>
int data_holder<DATA>::find(DATA const &to_compare)
{
    for(int i = 0; i < data_count; ++i)
        if(to_compare == data[i])
            return 1;
    return 0;
}

template<class DATA>
int data_holder<DATA>::compare(DATA const &to_compare)
{
    int i = 0;
    for(; i < data_count; ++i)
        if(data[i] >= to_compare)
            return i;
    //TODO we may want to return MAX_DATA
    /* Depends on if we want a node with one datum to have it's two children at index 0 and 4, or index 0 and 1.
     * Right now we're moving forward with index 0,1 */
    return i;
}

/* Bubble sort. We don't really care much about sorting speed, there are few data items per node */
template<class DATA>
int sort(DATA *array, int len)
{
    DATA temp;
    int i = 0, j = 0;

    /* Nested for loops and ifs are gross but so is the bubble sort */
    for(; i < len; ++i) {
        j = i;
        for(; j < len; ++j) {
            if(array[j] < array[i]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    return 1;
}