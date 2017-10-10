#include "data_obj.h"

namespace data_handle{


//Insert data into the class. We need a key and a data. This supports
//chaining so we need to check isfull() first!
template<class KEY, class DATA>
data_obj<KEY,DATA>& data_obj<KEY,DATA>::set(const KEY& new_key, const DATA& new_data)
{
    key = new_key;
    data = new_data;
    full = true;
}

//Is this node full? We need to check before inserting data!
template<class KEY, class DATA>
bool data_obj<KEY,DATA>::is_full() const
{
    return full;
}

/* Sets the full variable to false */
template<class KEY, class DATA>
data_obj<KEY,DATA> data_obj<KEY,DATA>::clear(void)
{
    full = false;
    return *this;
}

//Gets data from our object. This does not communicate 
//success/failure so we need to check with compare(KEY) first!
template<class KEY, class DATA>
DATA& data_obj<KEY,DATA>::get(void)
{
    return data;
}

/* Get data from the object and make a copy of it */
template<class KEY, class DATA>
DATA data_obj<KEY,DATA>::get_copy(void) const
{
    return new DATA(data);
}

/* Compare a key to the one we have.
 * Returns 0 if equal, >0 if we're greater, <0 if they're greater */
template<class KEY, class DATA>
int data_obj<KEY,DATA>::compare(const KEY& to_compare) const
{
    if(!full) return false;
    return key - to_compare;
}

/* Compare another key to our key
 * Returns 0 if equal, >0 if we're greater, <0 if they're greater */
template<class KEY, class DATA>
int data_obj<KEY,DATA>::compare(const data_obj<KEY,DATA>& to_compare) const
{
    /* Check if we're both empty */
    if(!full && !to_compare.full) return true;
    /* Check if just we are empty */
    else if( !full ) return false;
    return key - to_compare.key;
}

/* CONSTRUCTORS */
template<class KEY, class DATA>
data_obj<KEY,DATA>::data_obj()
{
    full = false;
}

template<class KEY, class DATA>
data_obj<KEY,DATA>::data_obj(const KEY& new_key, const DATA& new_data)
{
    key = new_key;
    data = new_data;
    full = true;
}

/* COPY CONSTRUCTOR */
template<class KEY, class DATA>
data_obj<KEY,DATA>::data_obj(const data_obj<KEY,DATA>& obj)
{
    key = obj.key;
    data = obj.data;
    full = obj.full;
}

/* DESTRUCTOR */
template<class KEY, class DATA>
data_obj<KEY,DATA>::~data_obj()
{
}

} /* namespace data_handle */
