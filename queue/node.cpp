#include "node.h"

/* NODE FUNCTIONS */
template<class DATA>
node<DATA>::node(const DATA& new_data)
{
    data = new_data;
    next = NULL;
}

template<class DATA>
node<DATA>::node(const node<DATA>& obj)
{
    data = obj.data;
    if( obj.next )
        next = new node(obj.next);
    else
        next = NULL;
}

template<class DATA>
node<DATA>::~node()
{
    next = NULL;
}

template<class DATA>
node<DATA>& node<DATA>::connect(node<DATA>* new_next)
{
    if(new_next && next)
        new_next -> next = next;
    next = new_next;
    return *this;
}

template<class DATA>
node<DATA>*& node<DATA>::go_next(void)
{
    return next;
}

template<class DATA>
DATA& node<DATA>::return_data(void)
{
    return data;
}

template<class DATA>
void node<DATA>::clear(void)
{
    if( next )
        next -> clear();
    delete next;
    next = NULL;
    return;
}
