#include <iostream>
using namespace std;
template<typename T>
T function(T a){}

template<>
int function(int a) {
    return a + 2;
}

template<>
double function(double a) {
    return a * 0.7;
}

void test_full_specialization() {
    int a = 3;
    cout << "Integer specialization:" << function(a) <<endl;
    double b = 1.2;
    cout << "Double specialization:" << function(b) <<endl;
}