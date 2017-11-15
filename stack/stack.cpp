#include "stack.h"

//STACK FUNCTIONS

//Push data onto the stack. If head node is full, we add a new one.
template <class T>
bool stack<T>::push(const T & data)
{
    if( !head )
    {
        head = new node_stack<T> (array_size);
        return head -> push( data );
    }
    if( head -> is_full() )
    {
        node_stack<T> * new_head = new node_stack<T>(array_size);
        new_head -> connect_next( head );
        head = new_head;
    }
    return head -> push( data );
}

//Pop data off of the stack. If head is empty, we move on to the next head.
//If there are no heads left, we return false.
template <class T>
bool stack<T>::pop(T & data)
{
    //Move onto the next head if this one is full
    if( head && head -> is_empty() )
    {
        node_stack<T> * new_head = head -> next_node();
        delete head;
        head = new_head;
    }
    //If head == NULL, then we're at the end of the stack.
    if( !head ) return false;
    return head -> pop( data );
}

//Peek at the data at the top of the stack without popping it off.
template <class T>
bool stack<T>::peek(T & data)
{
    if( !head ) return false;
    return head -> peek( data );
}

//Pop data off the stack and don't worry about returning it.
template <class T>
bool stack<T>::pop(void)
{
    if( !head ) return false;
    //Move onto the next head if this one is full
    if( head -> is_empty() )
    {
        node_stack<T> * new_head = head -> next_node();
        delete head;
        head = new_head;
    }
    //If head == NULL, then we're at the end of the stack.
    if( !head ) return false;
    return head -> pop();
}


//Is the stack empty? if so, return true;
template <class T>
bool stack<T>::is_empty(void)
{
    return !head;
}

template <class T>
stack<T>& stack<T>::operator=(const stack<T> & obj)
{
    remove_nodes();
    array_size = obj.array_size;
    copy_LLL(head, obj.head);
    return *this;
}

//Stack constructor
template <class T>
stack<T>::stack(unsigned int new_array_size)
{
    array_size = new_array_size;
    head = NULL;
}

//COPY CONSTRUCTOR
template <class T>
stack<T>::stack(const stack<T> & obj)
{
    array_size = obj.array_size;
    head = NULL;
    copy_LLL(head, obj.head);
}

//Recursively traverse the LLL of nodes and copy each. The first arg is this's
//head. The second arg is the head of the LLL we want to copy.
template <class T>
void stack<T>::copy_LLL(node_stack<T> *& self_head, 
        const node_stack<T> * orig_head)
{
    if( !orig_head ) return;
    //In case we have no head, we make a new one.
    if( !self_head )
    {
        self_head = new node_stack<T>( *orig_head );
        self_head -> connect_next(NULL);
        copy_LLL( self_head, orig_head -> next_node() );
        return;
    }

    //We need this's previous node because we need to connect. The nodes only
    //pass next_node() by value, not by ref.
    node_stack<T> * new_head = new node_stack<T>( *orig_head );
    self_head -> connect_next( new_head );
    copy_LLL( new_head, orig_head -> next_node() );
    return;
}

//Remove all the nodes in the stack. Used by the destructor, and assignment
//operator.
template <class T>
void stack<T>::remove_nodes(void)
{
    node_stack<T> * temp = NULL;
    while( head )
    {
        temp = head;
        head = head -> next_node();
        delete temp;
    }
    return;
}


//Deconstructor
template <class T>
stack<T>::~stack()
{
    remove_nodes();
}



//NODE FUNCTIONS

//This tell us if the node is full or not
template <class T>
bool node_stack<T>::is_full(void)
{
    return (index >= array_size);
}

//This tell us if the node is empty or not
template <class T>
bool node_stack<T>::is_empty(void)
{
    if( index == 0 ) return true;
    else return false;
}

//Pop data off of the array. Returns false if the array is empty, returns
//true if 
template <class T>
bool node_stack<T>::pop(T & data)
{
    //If index == 0, we know there's no data in the array.
    if( index == 0 ) return false;

    data = array[--index];
    return true;
}

//Pop data off, but do not return the data.
template <class T>
bool node_stack<T>::pop(void)
{
    //If index == 0, we know there's no data in the array.
    if( index == 0 ) return false;
    --index;
    return true;
}

//View the first data in the array witout popping it off the array.
template <class T>
bool node_stack<T>::peek(T & data)
{
    if( index == 0 ) return false;
    data = array[index-1];
}

//Push data onto the stack. Return false if there's no more room.
template <class T>
bool node_stack<T>::push(const T & data)
{
    if(index == array_size) return false;
    array[index++] = data;
    return true;
}


// Connect the next node in a LLL. This is to be used by the stack when we make
// a new head. The new head will need to connect to the rest of the LLL.
template <class T>
bool node_stack<T>::connect_next(node_stack * new_next)
{
    if( next ) return false;
    next = new_next;
    return true;
}

//This is when we finish with a node, we need to move onto the next in the LLL.
template <class T>
node_stack<T>* node_stack<T>::next_node(void) const
{
    return next;
}

//Assignment operator. The next node is NOT copied.
template <class T>
node_stack<T>& node_stack<T>::operator=(const node_stack<T> & obj)
{
    if( array ) delete [] array;
    array_size = obj.array_size;
    index = obj.index;
    next = NULL;

    //Copy over the data in the obj array.
    array = new T[array_size];
    //We create two local pointers to speed it up. One deref is faster than
    //one deref + index.
    T* local_current = array;
    T* obj_current = obj.array;
    for(int i = 0; i < index; ++i)
    {
        *local_current = *obj_current;
        ++local_current; ++obj_current;
    }
    return *this;
}

//Constructor
template <class T>
node_stack<T>::node_stack(unsigned int new_array_size)
{
    array_size = new_array_size;
    array = new T [array_size];

    index = 0;
    next = NULL;
}

//Copy constructor
template <class T>
node_stack<T>::node_stack(const node_stack & obj)
{
    array_size = obj.array_size;
    index = obj.index;

    int current_place = 0;
    array = new T [array_size];
    T* obj_current = obj.array;
    T* current = array;
    
    while( current_place < index )
    {
        *current = *obj_current;
        ++obj_current, ++current;
        ++current_place;
    }
    next = NULL;
}

//Destructor
template <class T>
node_stack<T>::~node_stack()
{
    delete [] array;
    array = NULL;
    next = NULL;
}

