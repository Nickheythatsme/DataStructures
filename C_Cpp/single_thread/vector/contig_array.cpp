#include "contig_array.h"

template<class T>
uint contig_array<T>::DEFAULT_SIZE = 16;

template<class T>
contig_array<T>::contig_array()
{
    initialize(DEFAULT_SIZE);
}

template<class T>
contig_array<T>::contig_array(std::initializer_list<T> l)
{
    len  = l.size();
    data = new T[len];

    uint i = 0;

    for (auto a = l.begin(); i < len; ++a,++i)
        data[i] = *a;
}

template<class T>
contig_array<T>::contig_array(uint new_len, std::initializer_list<T> l)
{
    len  = new_len;
    data = new T[len];

    uint i = 0;

    for (auto a = l.begin(); i < len; ++a,++i)
        data[i] = *a;
}

template<class T>
contig_array<T>::contig_array(uint len)
{
    initialize(len);
}

// COPY CONSTRUCTOR
template<class T>
contig_array<T>::contig_array(const contig_array<T> &obj)
{
    initialize(obj);
}

// DESTRUCTOR
template<class T>
contig_array<T>::~contig_array()
{
    delete [] data;
    _next = _prev = NULL;
}

// Access an element at index i
template<class T>
T& contig_array<T>::access(uint i)
{
    return data[i];
}

// Clear the data in this array, and make a new one
template<class T>
void contig_array<T>::clear()
{
    delete [] data;
    data = new T[len];
}

/* 
 * Initialize the data array to the obj_len, 
 * also initializes the length variable
 */
template<class T>
void contig_array<T>::initialize(uint obj_len)
{
    len  = obj_len;
    data = new T[len];
}

/*
 * Initialize this object's array to match the 
 * len, data array
 * of obj
 */
template<class T>
void contig_array<T>::initialize(const contig_array &obj)
{
    len  = obj.len;
    data = new T[len];

    for (auto i = 0lu; i < len; ++i)
        data[i]  = obj.data[i];
}
