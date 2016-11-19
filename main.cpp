#include <iostream>
#include <string>
#include <unordered_set>

#include "./lib/test_my_unordered_set.h"

using namespace std;

int main()
{
    try{

        test_my_unordered_set();
    }
    catch(const std::bad_alloc &err){

        cout << err.what() << endl;
    }
    catch(const std::runtime_error &err){

        cout << err.what() << endl;
    }

    return 0;
}
