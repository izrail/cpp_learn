#include <iostream>
#include "template/partial.hpp"
#include "const/const.hpp"
using namespace std;

int main() {
    cout << endl << endl << "-------------------test------------------" << endl;
    test_const();
    test_full_specialization();
    return 0;
}
