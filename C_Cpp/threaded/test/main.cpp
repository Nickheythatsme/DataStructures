#include <thread>
#include <iostream>
#include <unistd.h>
#include <vector>

using std::cout;
using std::endl;

void func()
{
    sleep(1);
    cout << "\tFinished sleeping" << endl;
}

int main(int argc, char **argv)
{
    std::vector<int> v {1,2,3,4};
    for( auto const & a : v)
        cout << a << endl;

    auto a = v.back();
    cout << endl << a << endl << endl;

    v.pop_back();
    for( auto const & a : v)
        cout << a << endl;

    v.clear();
    a = v.back();
    cout << endl << a << endl << endl;

}
