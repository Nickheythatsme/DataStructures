//
// Created by nick on 11/17/2017.
//
/*
 * This class just handles a single data point. It's a lot easier to handle keys and data when they're one object
 * so thats why we need this class. It essentially just uses operators and not much else
 */

#include <ostream>

#ifndef PROJECT_DATUM_H
#define PROJECT_DATUM_H


template<class KEY,class DATA>
class datum;

/* Relational operators */
template<class KEY,class DATA>
bool operator<(const datum<KEY,DATA> &obj1, const datum<KEY,DATA> &obj2);

template<class KEY,class DATA>
bool operator<=(const datum<KEY,DATA> &obj1, const datum<KEY,DATA> &obj2);

template<class KEY,class DATA>
bool operator==(const datum<KEY,DATA> &obj1, const datum<KEY,DATA> &obj2);

template<class KEY,class DATA>
bool operator>=(const datum<KEY,DATA> &obj1, const datum<KEY,DATA> &obj2);

template<class KEY,class DATA>
bool operator>(const datum<KEY,DATA> &obj1, const datum<KEY,DATA> &obj2);

/* Shift operators */
template<class KEY,class DATA>
std::ostream& operator<<(std::ostream& out, const datum<KEY,DATA> obj);

template<class KEY,class DATA>
class datum
{
    public:
        datum() = default;
        datum(const KEY &new_key, const DATA &new_data);
        datum(const datum &obj) = default;
        ~datum() = default;
        /* Assignment operators */
        datum<KEY,DATA>& operator=(const datum<KEY,DATA> &obj2);
        /* Relational operators */
        friend bool operator< <>(const datum<KEY,DATA> &obj1, const datum<KEY,DATA> &obj2);
        friend bool operator<= <>(const datum<KEY,DATA> &obj1, const datum<KEY,DATA> &obj2);
        friend bool operator== <>(const datum<KEY,DATA> &obj1, const datum<KEY,DATA> &obj2);
        friend bool operator>= <>(const datum<KEY,DATA> &obj1, const datum<KEY,DATA> &obj2);
        friend bool operator> <>(const datum<KEY,DATA> &obj1, const datum<KEY,DATA> &obj2);
        /* Shifting operator for ostream output */
        // TODO remove when we're finished with building tree
        friend std::ostream& operator<< <>(std::ostream& out, const datum<KEY,DATA> obj);
        /* Getter because we can't have assignment operators for other data types */
        void get_data(DATA& to_return) const;
        void get_key(KEY& to_return) const;
    protected:
        void set_key(const KEY &new_key);
        void set_data(const DATA &new_data);
    private:
        DATA data;
        KEY key;
};

#include "datum.cpp"

#endif //PROJECT_DATUM_H
