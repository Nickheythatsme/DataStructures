#include <stdlib.h>

#ifndef QUEUE_
#define QUEUE_

//namespace queue{

template<class DATA>
class node
{
    public:
        node() = delete;
        node(const DATA& new_data);
        node(const node<DATA>& obj);
        ~node();
        bool connect(node* next);
        bool is_done(void);
        bool set_done(bool finished);
    private:
        node<DATA>* next;
        DATA data;
};

template<class DATA>
class queue
{
    public:
        queue();
        queue(const queue<DATA>& to_copy);
        queue<DATA>& enqueue(const DATA& obj);
        queue<DATA>& dequeue(DATA& to_return);
        queue<DATA>& clear(void);
    protected:
        node<DATA>* head;
        node<DATA>* tail;
};

//}
#endif
