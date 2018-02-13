#include <cstdlib>
#include "node.h"

#ifndef QUEUE_
#define QUEUE_

//namespace queue{


template<class DATA>
class queue
{
    public:
        queue();
        queue(const queue<DATA>& to_copy);
        ~queue();
        queue<DATA>& enqueue(const DATA& obj);
        queue<DATA>& dequeue(DATA& to_return);
        queue<DATA>& clear(void);
        void find_tail(void);
        bool is_empty(void) const;
    protected:
        node<DATA>* head;
        node<DATA>* tail;
};

//}
#include "queue.cpp"
#endif
