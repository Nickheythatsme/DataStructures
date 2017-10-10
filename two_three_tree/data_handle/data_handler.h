#include "data_obj.h"


#ifndef DATA_HANDLER_
#define DATA_HANDLER_

template <class KEY, class DATA>
class data_handler
{
    public:
        data_handler();
        data_handler(const data_handler<KEY,DATA>& obj);
        data_handler(const data_obj& obj);
    private:
        /* Array of data_objects */
        data_obj* data_objs;
};


#endif
