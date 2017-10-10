#include "data_obj.h"
#include <string>
#include <iostream>

using namespace std;
using namespace data_handle;

int main(int argc, char* argv[])
{
    string key = "Test Key";
    string data = "Test Data";

    string key2 = "Key 2";
    string data2 = "Data 2";

    data_obj<string, string> test(key,data);
    data_obj<string, string> test2(key2,data2);

    cout << test.get() << endl;

    return 0;
}
