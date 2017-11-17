//
// Created by nick on 11/17/2017.
//

#include "node.h"
#include <random>
#include <sys/time.h>
#include <iostream>

using std::cout;
using std::endl;

void test_insert_rand();

int main()
{
    test_insert_rand();
    cout << "Sizeof node: " << sizeof(node<int,int>) << endl;
}

/* NODE TESTS */
#define SIZE 10000
#define ITERATIONS 10

void test_insert_rand()
{
    //TODO fix node declarations
    int temp = 0;
    datum<int,int> temp_datum(500,500);
    datum<int,int> start_datum(500,500);
    auto *root = new node<int,int> (start_datum);
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,1000);

    /* Record the time of execution */
    struct timeval tf{}, ti{};
    time_t timems=0;
    gettimeofday(&ti,nullptr);

    /* Start test */
    for(int j = 0; j < ITERATIONS; ++j)
    {
        temp = distribution(generator);
        temp_datum.set_data(temp);
        temp_datum.set_key(temp);
        for(int i = 0; i < SIZE; ++i)
            root -> insert(temp_datum);
        delete root;
        root = new node<int,int>(start_datum);
    }

    /* Output results */
    gettimeofday(&tf,nullptr);
    timems=(tf.tv_sec*1000+tf.tv_usec/1000) - (ti.tv_sec*1000+ti.tv_usec/1000);
    cout << "Amount of data: " << SIZE << endl
         << "Iterations: " << ITERATIONS << endl
         << "TotalTime: " << timems << " ms" << endl
         << "Time per iteration: " << (timems / (float) ITERATIONS) << " ms" << endl;

    delete root;
}

