//#include "worker.h"
#include "queue.h"
#include <iostream>
#include <unistd.h>
#include <string>

using namespace std;

// Declare the type of arguments to be used
struct f_array
{
    f_array()
    {
        a = nullptr;
        len = 0;
    }
    f_array(uint _len)
    {
        len = _len;
        a = new float[len];
    }
    ~f_array() 
    {
        if(a) delete [] a;
    }
    float *a;
    uint len;
};

// Declare the type of function to be called
typedef void func(f_array *);

void test_func(f_array *s)
{
    for(uint j = 0; j < s->len; ++j)
        for(uint i = 0; i < s->len; ++i)
            s->a[i] *= 1000;
}


f_array* make_array()
{
    srand(clock());
    //auto n = new f_array(rand() % 10000);
    auto n = new f_array(10000);

    for(uint i = 0; i < n->len; ++i)
    {
        n->a[i] = rand() % 1000;
    }
    return n;
}

std::vector<f_array*> make_arrays(uint count)
{
    std::vector<f_array*> ret;
    for(uint i = 0; i < count; ++i)
    {
        ret.emplace_back(make_array());
    }
    return ret;
}

int main(int argc, char **argv)
{
    auto v = make_arrays(4);
    test_func(v.back());
    printf("done\n");
    getchar();
    queue<func,f_array*> q(test_func, v, 4);

    auto start = time(NULL);

    try{
        auto ret = q.start();
        for(auto &a : ret)
            delete a;
    }
    catch(queue_error e)
    {
        cout << e << endl;
    }

    auto end = time(NULL);
    printf("Running time: %d\n", end-start);

    return 0;
}
