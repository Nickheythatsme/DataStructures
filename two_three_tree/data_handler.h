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
 * we have another class, data_handler, which will be the base for the node,
 * and will support all comparisons, insertions, extractions of data. The node
 * class will then be inherited from his data_handler class.
 */


#ifndef DATA_HANDLER_
#define DATA_HANDLER_

template<class KEY, class DATA>
class data_handler
{
    public:
        data_handler();
        data_handler(KEY key, DATA data);
        data_handler(data_hander<KEY,DATA>& obj);
        ~data_handler();
        //Insert data into the class. We need a key and a data. This supports
        //chaining so we need to check isfull() first!
        data_handler<KEY,DATA>& insert(KEY& key, DATA& data);
        //Is this node full? We need to check before inserting data!
        bool isfull();
        //Gets a key from one that we have. This does not communicate 
        //success/failure so we need to check with compare(KEY) first!
        KEY& access(KEY& to_access);
        //Compare a key to the ones we have. Returns TRUE if we have it!
        bool compare(KEY& to_compare);
    private:
        KEY* key;   /* array of two keys  */
        DATA* data; /* array of two datum */
};

#include "data_handler.cpp"
#endif
