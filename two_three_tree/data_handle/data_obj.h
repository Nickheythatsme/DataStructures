#include <stdlib.h>
#include <iostream>
/* Nick Grout 9/26
 * 
 * So we have a problem with our tree in that it is extremely limited in it's
 * use. We want to be able to declare it as tree<KEY,DATA> where key is a class
 * that supports relational and equality operators and data can be anything.
 * The tree will need to search and compare KEYS, not data, then return the 
 * data that key refers to.
 *
 * This is more complicated because each node has two data points. This is why
 * we have another class, data_obj, which will be the base for the node,
 * and will support all comparisons, insertions, extractions of data. The node
 * class will then be inherited from his data_obj class.
 */


#ifndef DATA_OBJ_
#define DATA_OBJ_

namespace data_handle{

template<class KEY, class DATA>
class data_obj
{
    public:
        data_obj();
        data_obj(const KEY& key, const DATA& data);
        data_obj(const data_obj<KEY,DATA>& obj);
        ~data_obj();
        //Insert data into the class. We need a key and a data. This supports
        //chaining so we need to check isfull() first!
        data_obj<KEY,DATA>& set(const KEY& key, const DATA& data);
        //Is this node full? We need to check before inserting data!
        bool is_full() const;
        /* Sets the full state to empty */
        data_obj<KEY,DATA> clear(void);
        //Gets data from the object. This does not communicate 
        //success/failure so we need to check with compare(KEY) first!
        DATA& get(void);
        /* Get the data but make a new copy */
        DATA get_copy(void) const;
        //Compare a key to the ones we have. Returns TRUE if we have it!
        int compare(const KEY& to_compare) const;
        /* Compare another object to our object */
        int compare(const data_obj<KEY,DATA>& to_compare) const;
    private:
        KEY key;   /* array of two keys  */
        DATA data; /* array of two datum */
        bool full;
};

} /* namespace data_handle */

#include "data_obj.cpp"
#endif
