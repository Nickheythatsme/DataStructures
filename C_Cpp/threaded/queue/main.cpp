//#include "worker.h"
#include "queue.h"
#include <iostream>
#include <unistd.h>
#include <string>

using namespace std;

// Declare the type of arguments to be used
struct args
{
    const char *message;
};

// Declare the type of function to be called
typedef void func(int);


void test_func(int a)
{
    cout << a << endl;
    sleep(2);
}

int main(int argc, char **argv)
{
    //std::vector<int> v {0,1,2,3,4,5};
    //queue<func,int> q(test_func, v);
    worker<func,int> w(test_func);
    //auto *array = new worker<func,int>[2] {worker<func,int>(w)};
    auto strings = new std::string[2] {"this","that"};
    auto b = 

    try{
        //q.start();
    }
    catch(queue_error e)
    {
        cout << e << endl;
    }

    return 0;
}
