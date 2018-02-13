#include "queue.h"
#include <iostream>

using std::cout;
using std::endl;


int main(int argc, char* argv[])
{
    int return_test = 0;
    queue<int> test_queue;

    for(int i = 0; i < 100; ++i)
        test_queue.enqueue(i);

    while(!test_queue.is_empty())
    {
        test_queue.dequeue(return_test);
        cout << return_test << endl;
    }
    return 0;
}
