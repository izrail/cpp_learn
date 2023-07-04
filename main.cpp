#include <iostream>
#include "template/partial.hpp"
#include "const/const.hpp"
#include "friend_function/friend.hpp"
#include "complex/complex.hpp"
#include <vector>
#include <algorithm>
#include "conv2d/conv2d.hpp"

using namespace std;

int main() {
    cout << endl << "-------------------test start.------------------" << endl;
    test_const();
    test_full_specialization();
    test_friend_function();

    Complex a(2.5, 3.0);
    // a.print(1,2.3, "asdf");
    Complex b(a);
    Complex C(std::move(a));
    Complex d = a;
    Complex e = std::move(a);
    d = a;
    e = std::move(a);
    Complex aa(3.3, 4.8);
    Complex cc = aa + a;
    cout << "result:" << cc.getIm() << endl;
    cout << "func name:" << __func__ <<endl;

    Conv2d conv1(1, 10, 10, 3, 1, 3, 3);
    conv1.init();
    Op *op = &conv1;
    op->run();
    conv1.result();
    vector<int>v = {1, 3, 8, 9, 18, 87, 34};
    for_each(v.begin(), v.end(), [](const int& n){ cout << n << endl;});
    for_each_n(v.begin(), 3, [](const int& n){ cout << n << endl;});
    if(any_of(v.begin(), v.end(), [](const int& n){ return n % 2 == 0; })) {
        cout << "vector exsit even number." <<endl;
    }

    if(all_of(v.begin(), v.end(), [](const int& n){ return n > 0; })) {
        cout << "vector don’t own negative number." <<endl;
    }

    if(none_of(v.begin(), v.end(), [](const int&n){ return n < 0;})) {
        cout << "vector don’t own negative number." <<endl;
    }
    cout << "equal 18 number=" << count(v.begin(), v.end(), 18) << endl;
    cout << "total number of v =" << count_if(v.begin(), v.end(), [](auto){return true;}) << endl;
    return 0;

}
