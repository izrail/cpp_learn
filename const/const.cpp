#include<iostream>
#include "const.hpp"
using namespace std;

/**
1. const和constexpr的区别
const修饰变量可以使变量在编译期只读，constexpr是真正的常量（一个值，非变量的值，诞生于编译期）
const和constexpr都是修饰符，
当使用const修饰变量表达这个变量不可以被更改只可以被读取

但是const也并非只读，这个只读只是一个编译期的概念，在运行期依然可以修改其值，例下：
*/

/**
2. 定义常量选择 #define还是constexpr？

见c++源码<limits> <limits.h>头文件，limits头文件用于声明各种数据类型的最大最小值等常量，使用static constexpr int CHAR_MAX = 123;
在limits.h头文件中，使用#define CHAR_MAX 123
结论：在c-type代码中使用#define，在cpp-type代码中使用constexpr

*/

/**
const修改函数参数
表示该参数在函数中无法被修改，即只读，（例外见问题1）

**/

// 无法成功执行，报错信息如下：
// error: assignment of read-only reference 'a'
// error: assignment of read-only reference 'b'
// 通过报错可以看出，a，b为read-only的reference，不能够被assignment
// void print(const int& a, const int& b) {
//     a = 3;
//     b = 4;
//     cout << a << b << endl;
// }


/**
const修饰函数
在 c语言中const无法修饰函数，const修饰函数是c++新增语法，
使用方式是放在函数列表的圆括号后，语义为整个函数内部不允许赋值修改动作。
需要注意non-const的object无法直接调用 const member function, 如果需要可以通过const_cast先转换对象为const 类型。
*/

/**
const修饰指针，代表指针不可以被更改
*/

/**
const修饰函数返回值
一般情况下函数的返回值是rvalue，不会被修改不需要const修饰
但当函数返回值为引用、指针类型时，防止返回值被修改在函数返回值处加上const修饰符
*/

/**
mutable修饰的变量可以更改const的属性，但是二者不会同时修饰函数，对象等，const修饰的函数，约定该函数不可修改，不过如何函数中的数据类型为mutable类型
依然可以修改*/

int& fun(int& t) {
    return t;
}
/*
关于const意见，写cpp时要多使用const，设计每个函数都应该思考三个问题：
这个函数的会修改变量吗，不会修改请修饰函数以及函数参数
函数是否会修改函数参数，不会请修饰函数参数

*/

void test_const() {
    cout << "test const start." << endl;
     int num = 3;
    const int* const_value = &num;
    cout << "the value is " << *const_value << " before change const_value." << endl;
    int *p = &num;
    *p = 4;
    cout << "the value is " << *const_value << " after change const_value." << endl;
    // int a = 1, b = 1;
    // print(a, b);
    int t = 4;
    fun(t) = 5;
    cout << "t is " << t << endl;
    cout << "test const end." << endl;
}