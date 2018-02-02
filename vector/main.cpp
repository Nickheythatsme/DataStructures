#include "contig_array.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
    contig_array<int> a {23,1,100};
    cout << a.access(0);
}

