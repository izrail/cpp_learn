#include <iostream>
#include "template/partial.hpp"
#include "const/const.hpp"
#include "friend_function/friend.hpp"
using namespace std;

int main() {
    cout << endl << endl << "-------------------test------------------" << endl;
    test_const();
    test_full_specialization();
    test_friend_function();
    return 0;
}
