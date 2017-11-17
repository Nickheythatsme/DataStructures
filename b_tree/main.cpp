//
// Created by Nick Grout on 10/29/17.
//

#include "node.h"
#include <random>
#include <cstring>
#include <sys/time.h>
#include <fstream>
#include "datum.h"

using std::cout;
using std::endl;


#define ITERATIONS 10000
#define INCREMENT 100

char FILEOUT[] = "b_tree_results.csv";

/* Testing Tree functions */
void O();

int main(int argc, char *argv[])
{
    O();
    return 0;
}

/* TODO BIG O for the following features:
 *
 * insertion (FINISHED)
 * finding
 * deleting
 * clearing
 */

time_t O_insertion(int data_size)
{
    auto *root = new node<int,int>;
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
        node<int,int>::insert(datum_array[i], root);

    /* Output results */
    gettimeofday(&tf,nullptr);
    timems=(tf.tv_sec*1000+tf.tv_usec/1000) - (ti.tv_sec*1000+ti.tv_usec/1000);
    root -> clear();
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
