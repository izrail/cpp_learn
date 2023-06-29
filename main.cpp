#include <iostream>
#include "template/partial.hpp"
#include "const/const.hpp"
#include "friend_function/friend.hpp"
#include "complex/complex.hpp"
using namespace std;

int main() {
    cout << endl << endl << "-------------------test------------------" << endl;
    test_const();
    test_full_specialization();
    test_friend_function();

    Complex a(2.5, 3.0);
    a.print(1,2.3, "asdf");
    Complex b(a);
    Complex C(std::move(a));
    Complex d = a;
    Complex e = std::move(a);
    d = a;
    e = std::move(a);
    return 0;

}
