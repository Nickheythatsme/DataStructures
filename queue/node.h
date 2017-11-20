
#include <stdlib.h>

#ifndef NODE_QUEUE_
#define NODE_QUEUE_

template<class DATA>
class node
{
    public:
        node() = delete;
        node(const DATA& new_data);
        node(const node<DATA>& obj);
        ~node();
        node<DATA>& connect(node<DATA>* next);
        void clear(void);
        node<DATA>*& go_next(void);
        DATA& return_data(void);
    private:
        int head_index;
        int tail_index;
        node<DATA>* next;
        DATA* data;
};

#include "node.cpp"

#endif
