#include <stdlib.h>
#include <stdint.h>
#include <initializer_list>

#ifndef CONTIG_ARRAY_
#define CONTIG_ARRAY_

//#define DEFAULT_SIZE 16

template<class T>
class contig_array
{
    //protected:
    //TODO make all protected when not testing
    public:
        contig_array();
        contig_array(std::initializer_list<T> l);
        contig_array(uint len, std::initializer_list<T> l);
        explicit contig_array(uint len);
        contig_array(const contig_array<T> &obj);
        ~contig_array();

        // Access an element at index i
        T& access(uint i);

        // Connect another contig_array
        void connect_next(contig_array *next);
        void connect_prev(contig_array *prev);

        // Move onto the next/prev contig_array
        contig_array* next();
        contig_array* prev();
    private:
        // Reinitializes the whole array
        void clear();

        // Initialize this data array
        void initialize(uint len);

        // Initialize this data array to match obj's data array
        void initialize(const contig_array &obj);

        // Pointers to the next/prev contig_array objects 
        contig_array *_next;
        contig_array *_prev;

        T* data;     // Data array
        uint len;

        static uint DEFAULT_SIZE;
};

#include "contig_array.cpp"

#endif// CONTIG_ARRAY_
