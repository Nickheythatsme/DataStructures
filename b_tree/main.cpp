//
// Created by Nick Grout on 10/29/17.
//

#include "node.h"
#include <random>
#include <cstring>
#include <sys/time.h>
#include <string>
#include "datum.h"

using std::cout;
using std::endl;

/* Node functions */
void test_insert_planned();
void test_insert_rand();
void test_datum();

int main(int argc, char *argv[])
{
    test_datum();
    /*
    if( argc > 1 && !strncmp(argv[1],"--rand",6) )
        test_insert_rand();
    else
        test_insert_planned();
    cout << "sizeof a node: " << sizeof(node<int>) << endl;
     */

    return 0;
}


/* NODE TESTS */
#define SIZE 10000
#define ITERATIONS 1000

void test_insert_rand()
{
    auto *root = new node<int>;
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
            node<int>::insert(distribution(generator), root);
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

#define MAX 100
#define LEN 11
void test_insert_planned()
{
    auto *root = new node<int>;
    int data[] = {100,90,110,80,120,70,130,60,140,50,150};

    for(int i = 0; i < LEN; ++i) {
        cout << i+1 << ") Inserting: " << data[i] << endl;
        node<int>::insert(data[i], root);
        root->display(cout);
        cout << endl << endl;
    }
    root -> clear();
    delete root;
}

#undef LEN
#undef MAX


using std::string;
void test_datum()
{
    //datum<string, string> datum1;
    //datum<string, string> datum2;
    int retreive = 0;
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

    datum1.get_data(retreive);
    cout << retreive << endl; //3
}
