#include <iostream>
#include "X.h"

using std::cout;
using std::endl;

void reference_overload(X& x)
{
    cout << "LVALUE OVERLOAD CALLED" << endl;
}

#if __cplusplus >= 201103
void reference_overload(X&& x)
{
    cout << "RVALUE OVERLOAD CALLED" << endl;
    auto x1(x);
}
#endif

X return_X()
{
    X x;
    x.perform_operation();
    return x;
}



int main(int argc, char **argv)
{
    // Here the constructor is only called once.
    X x1 = return_X();

    cout << __cplusplus << endl;

    cout << endl << endl;
}
