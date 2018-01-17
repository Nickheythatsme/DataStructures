//
// Created by Nick Grout on 10/29/17.
//
/* TODO BIG O for the following features:
 *
 * insertion (FINISHED)
 * finding
 * deleting
 * clearing
 */

#include "b_tree.h"
#include <random>
#include <sys/time.h>
#include <fstream>
#include <iostream>

#define MAX_DATA_SIZE 500000 //Maximum data size to test

using std::cout;
using std::endl;

/* BIG O test functions */
void O(long iterations); //Main tester
void test_time(const char* fileout, long iterations, time_t (*test_func)(long) );

//Insertion
time_t insertion(long data_size); //test insertion time

//Find
time_t find(long data_size); //test find time


void O(long iterations)
{
//    test_time("insertion.csv",iterations,(*insertion));
    test_time("find.csv",iterations,(*find));
}

void test_time(const char* fileout, long iterations, time_t (*test_func)(long) )
{
    long increment = MAX_DATA_SIZE / iterations;
    long data_size = increment;
    time_t result;
    std::ofstream fout(fileout);

    /* Test insertion */
    for(long i = 0; i < iterations; ++i)
    {
        result = (*test_func) (data_size);
        fout << i << "," << data_size << "," << result << endl;
        cout << i << "," << data_size << "," << result << endl;
        data_size += increment;
    }
    fout.close();
}

//Insertion
time_t insertion(long data_size)
{
    b_tree<int,int> b_test;
    datum<int,int> datum_array[data_size];

    int temp;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,1000);

    /* Create array of randomness */
    for(long i = 0; i < data_size; ++i)
    {
        temp = distribution(generator);
        datum_array[i].set_data(temp);
        datum_array[i].set_key(temp);
    }

    /* Record the time of execution */
    struct timeval tf{}, ti{};
    time_t timems=0;
    gettimeofday(&ti,nullptr);

    /* Start test */
    for(long i = 0; i < data_size; ++i)
        b_test.insert(datum_array[i]);

    /* Output results */
    gettimeofday(&tf,nullptr);
    timems=(tf.tv_sec*1000+tf.tv_usec/1000) - (ti.tv_sec*1000+ti.tv_usec/1000);
    return timems;
}

//FIND
time_t find(long data_size)
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,data_size);
    b_tree<int,int> b_test;
    int array[data_size];
    int temp_v; //temp value
    int temp_i; //temp index

    for(long i = 0; i < data_size; ++i)
        array[i] = i;

    for(long i = 0; i < data_size; ++i)
    {
        temp_i = distribution(generator);
        temp_v = array[i];
        array[i] = array[temp_i];
        array[temp_i] = temp_v;
    }

    for(long i = 0; i < data_size; ++i)
        b_test.insert(array[i],array[i]);

    /* Record the time of execution */
    struct timeval tf{}, ti{};
    time_t timems=0;
    gettimeofday(&ti,nullptr);

    int to_return;
    for(long i = 0; i < data_size; ++i)
    {
        temp_i = distribution(generator);
        b_test.find(array[temp_i], to_return);
    }


    /* Output results */
    gettimeofday(&tf,nullptr);
    timems=(tf.tv_sec*1000+tf.tv_usec/1000) - (ti.tv_sec*1000+ti.tv_usec/1000);
    return timems;
}
