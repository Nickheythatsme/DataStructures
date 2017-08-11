#include <stdlib.h>
#include <iostream>
using namespace std;


#ifndef STACK_
#define STACK_

//The node_stack class handles one individual array. This makes it easier
//to change the stack and simplifies it. Possibly we can use the node_stack
//on other classes in the future.
template <class T>
class node_stack
{
    public:
        node_stack(unsigned int new_array_size);
        node_stack(const node_stack & obj);
        virtual ~node_stack();
        bool push(const T & data);
        bool pop(T & data);
        bool pop(void);
        bool peek(T & data);
        bool is_full(void);
        bool is_empty(void);
        node_stack<T>* next_node(void) const; 
        bool connect_next(node_stack * next);
        //TODO implement assignment op. The next node is not copied.
        node_stack<T>& operator=(const node_stack<T> & obj);
    private:
        T * array;
        int array_size;
        int index;
        node_stack * next;
};


template <class T>
class stack
{
    public:
        stack(unsigned int array_size);
        stack(const stack<T> & obj);
        virtual ~stack();
        //This copies the LLL from another stack into this stack. This is used
        //by the copy constructor, and the assignment operator.
        void copy_LLL(node_stack<T> *& self_head, 
                const node_stack<T> *  new_head);
        bool push(const T & data);
        bool pop(T & data);
        bool pop(void);
        bool peek(T & data);
        bool is_empty(void);
        //TODO implement assignment op and << op.
        stack<T>& operator=(const stack<T> & obj);
        stack<T>& operator<<(const T & obj);
    protected:
        node_stack<T> * head;
        int array_size;
    private:
        void remove_nodes(void);
};

#include "stack.cpp"
#endif
