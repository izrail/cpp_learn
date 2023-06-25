#include<iostream>
#include<chrono>
#include"friend.hpp"
using namespace std;

int fun(A&a) {
    return a.num;
}
int A::getA(){
    return num;
}

/*
输出：
friend fun total time is 186.184
member fun total time is 215.218

友元函数在访问数据时表现出了更优良的性能，我不理解
*/
void test_friend_function() {
    A a(1);
    auto begin = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < 100000; i++) {
        fun(a);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto result = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "friend fun total time is " << result.count() * 1e-3 << endl;
    
    auto begin1 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < 100000; i++) {
        a.getA();
    }
    auto end1 = std::chrono::high_resolution_clock::now();
    auto result1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - begin1);
    cout << "member fun total time is " << result1.count() * 1e-3 << endl;
}
