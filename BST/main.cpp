//
// Created by nick on 11/17/2017.
//

#include "node.h"
#include <random>
#include <sys/time.h>
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;



#define ITERATIONS 10000
#define INCREMENT 100

char FILEOUT[] = "BST_results.csv";

/* Testing Tree functions */
void O();

int main()
{
    O();
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


void O()
{
    int data_size = INCREMENT;
    std::ofstream fout(FILEOUT);
    time_t result;

    for(int i = 0; i < ITERATIONS; ++i)
    {
        result = O_insertion(data_size);
        fout << i << "," << data_size << "," << result << endl;
        cout << i << "," << data_size << "," << result << endl;
        data_size += INCREMENT;
    }
    fout.close();
    return;
}

#undef ITERATIONS
#undef INCREMENT
