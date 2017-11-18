//
// Created by nick on 11/17/2017.
//

#include "node.h"
#include <random>
#include <sys/time.h>
#include <fstream>
#include <iostream>

using std::cout;
using std::endl;

#define MAX_DATA_SIZE 100000 //Maximum data size to test

static char FILEOUT[] = "BST_results.csv";

/* Testing Tree functions */
void O(int i);

int main(int argc, char *argv[])
{
    int iterations;
    if( argc != 2 )
    {
        cout << "Usage: ./b_tree [ITERATIONS]" << endl;
        return 1;
    }
    sscanf(argv[1],"%d",&iterations);
    O(iterations);
    return 0;
}

time_t O_insertion(int data_size)
{
    auto *root = new node<int,int>(datum<int,int>(500,500));
    datum<int,int> datum_array[data_size];

    int temp;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,1000);

    /* Create array of randomness */
    for(int i = 0; i < data_size; ++i)
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
    for(int i = 0; i < data_size; ++i)
        root -> insert(datum_array[i]);

    /* Output results */
    gettimeofday(&tf,nullptr);
    timems=(tf.tv_sec*1000+tf.tv_usec/1000) - (ti.tv_sec*1000+ti.tv_usec/1000);
    delete root;
    return timems;
}


void O(int iterations)
{
    int increment = MAX_DATA_SIZE / iterations;
    int data_size = increment;
    std::ofstream fout(FILEOUT);
    time_t result;

    cout << "Testing for BST" << endl;
    fout << "Testing for BST" << endl;

    for(int i = 0; i < iterations; ++i)
    {
        result = O_insertion(data_size);
        fout << i << "," << data_size << "," << result << endl;
        cout << i << "," << data_size << "," << result << endl;
        data_size += increment;
    }
    fout.close();
    return;
}

#undef ITERATIONS
#undef INCREMENT
