#include "worker.h"
#include <iostream>

using namespace std;

// Declare the type of arguments to be used
struct array_args
{
    int* array;
    int len;
    const char *message;
};

// Declare the type of function to be called
typedef int& func(array_args *a);


int& test_func(array_args *a)
{
    cout << "Displaying: " << a->message << endl;
    for(auto i = 0; i < a->len; ++i)
        cout << a->array[i] << ", ";
    cout << endl;
    return a->len;
}

int main(int argc, char **argv)
{
    int array[] = {1,2,3,4};
    array_args a = {
        array,
        4,
        "this message"};

    worker<func,array_args> w(test_func);

    try{
        w.run(&a);
        w.run(&a);
    }
    catch(err_running e)
    {
        cout << e << endl;
    }

    return 0;
}
