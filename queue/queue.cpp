#include "queue.h"

template<class DATA>
queue<DATA>::queue()
{
    head = tail = NULL;
}

template<class DATA>
queue<DATA>::queue(const queue<DATA>& to_copy)
{
    if(to_copy.head)
    {
        head = new node<DATA>(to_copy.head);
        find_tail(tail);
    }
    else
        head = tail = NULL;
}

/* Find the tail after copying the LLL of the other queue. It kills me to not
 * do this recursively but it seems like calling this function repeatidly will
 * be more work than doing it iteratively, when all we need to do is traversal
 *
 * Returns nothing. Finds the tail of the LLL */
template<class DATA>
void queue<DATA>::find_tail(void)
{
    tail = head;
    while( tail && tail -> go_next() )
        tail = tail -> go_next();
    return;
}

template<class DATA>
queue<DATA>::~queue()
{
    clear();
}

template<class DATA>
queue<DATA>& queue<DATA>::enqueue(const DATA& obj)
{
    node<DATA>* new_node = new node<DATA>(obj);
    if(!head)
    {
        tail = head = new_node;
        return *this;
    }
    tail -> connect(new_node);
    tail = tail -> go_next();
    return *this;
}

template<class DATA>
queue<DATA>& queue<DATA>::dequeue(DATA& to_return)
{
    if(!head) return *this;

    to_return = head -> return_data();
    node<DATA>* temp = head;
    head = head -> go_next();
    delete temp;
    return *this;
}

template<class DATA>
bool queue<DATA>::is_empty(void) const
{
    return head == NULL;
}

template<class DATA>
queue<DATA>& queue<DATA>::clear(void)
{
    if(head)
    {
        head -> clear();
        delete head;
    }
    head = tail = NULL;
    return *this;
}

