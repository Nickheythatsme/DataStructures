//
// Created by Nick Grout on 10/29/17.
//

#include "node.h"
#include <random>
#include <cstring>
#include <sys/time.h>
#include <string>
#include <fstream>
#include "datum.h"

using std::cout;
using std::endl;

/* Node functions */
void test_insert_rand();
void test_datum();
void O();

int main(int argc, char *argv[])
{
    //test_insert_rand();
    O();
    //cout << "sizeof a node: " << sizeof(node<int,int>) << endl;

    return 0;
}

/* BIG O for the following features:
 *
 * insertion
 * finding
 * deleting
 * clearing
 */

time_t O_insertion(int data_size)
{
    auto *root = new node<int,int>;
    int temp = 0;
    datum<int,int> temp_datum(0,0);
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,1000);

    /* Record the time of execution */
    struct timeval tf{}, ti{};
    time_t timems=0;
    gettimeofday(&ti,nullptr);

    /* Start test */

    for(int i = 0; i < data_size; ++i)
    {
        temp = distribution(generator);
        temp_datum.set_data(temp);
        temp_datum.set_key(temp);
        node<int,int>::insert(temp_datum, root);
    }

    /* Output results */
    gettimeofday(&tf,nullptr);
    timems=(tf.tv_sec*1000+tf.tv_usec/1000) - (ti.tv_sec*1000+ti.tv_usec/1000);
    root -> clear();
    delete root;
    return timems;
}

#define ITERATIONS 10000
#define INCREMENT 100
void O()
{
    int data_size = INCREMENT;
    std::ofstream fout("results.txt");
    time_t result;

    for(int i = 0; i < ITERATIONS; ++i)
    {
        result = O_insertion(data_size);
        fout << i << "," << data_size << "," << result << endl;
        cout << i << "," << data_size << "," << result << endl;
        data_size += INCREMENT;
    }
    return;
}

#undef ITERATIONS
#undef INCREMENT


/* NODE TESTS */
#define SIZE 10000
#define ITERATIONS 1000

void test_insert_rand()
{
    //TODO fix node declarations
    auto *root = new node<int,int>;
    int temp = 0;
    datum<int,int> temp_datum(0,0);
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,1000);

    /* Record the time of execution */
    struct timeval tf{}, ti{};
    time_t timems=0;
    gettimeofday(&ti,nullptr);

    /* Start test */
    for(int j = 0; j < ITERATIONS; ++j)
    {
        for(int i = 0; i < SIZE; ++i)
        {
            temp = distribution(generator);
            temp_datum.set_data(temp);
            temp_datum.set_key(temp);
            node<int,int>::insert(temp_datum, root);
        }
        root -> clear();
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

#undef SIZE
#undef ITERATIONS


using std::string;
void test_datum()
{
    //datum<string, string> datum1;
    //datum<string, string> datum2;
    int to_return = 0;
    datum<int, int> datum1(1,1);
    datum<int, int> datum2(2,2);
    datum<int, int> datum3(3,3);
    datum<int, int> datum3b(3,3);

    cout << (datum1 < datum2) << endl    //1
         << (datum1 <= datum2) << endl   //1
         << (datum1 > datum2) << endl    //0
         << (datum1 == datum2) << endl   //0
         << (datum3 == datum3b) << endl  //1
         << (datum3 >= datum2) << endl   //1
         << (datum3 >= datum3b) << endl  //1
         << (datum3 <= datum3b) << endl; //1
    datum1 = datum3;
    cout << datum1 << endl; //3

    datum1.get_data(to_return);
    cout << to_return << endl; //3
}
