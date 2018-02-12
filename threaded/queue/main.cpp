#include "queue.h"
#include <iostream>

using namespace std;
typedef int worker(int *array, int len);

int w(int *array, int len)
{
    for(auto i = 0; i < len; ++i)
        cout << array[i] << ", ";
    cout << endl;
    return len;
}


void test_pass_func(worker *w)
{
    int a[] = {1,2,3};
    int len = 3;
    cout << "Len: " << w(a, len) << endl;
}

int main(int argc, char **argv)
{
    test_pass_func(w);
    return 0;
}
