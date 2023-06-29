#include "complex.hpp"
#include <iostream>
using namespace std;

Complex::Complex(Complex& complex) {
	cout << "copy constructor." << endl;
	cout << (std::is_lvalue_reference<decltype(complex)>::value ? "lvalue" : "rvalue") << endl;
	this->a_ = complex.getRe();
	this->b_ = complex.getIm();
}

Complex::Complex(Complex&& complex) {
	cout << "move constructor. " << endl;
	cout << (std::is_lvalue_reference<decltype(complex)>::value ? "lvalue" : "rvalue") << endl;
	this->a_ = complex.getRe();
	this->b_ = complex.getIm();
}

void Complex::operator =(Complex& complex) {
	cout << "copy assignment." << endl;
	cout << (std::is_lvalue_reference<decltype(complex)>::value ? "lvalue" : "rvalue") << endl;
	this->a_ = complex.getRe();
	this->b_ = complex.getIm();
}

void Complex::operator =(Complex&& complex) {
	cout << "move assignment." << endl;
	cout << (std::is_lvalue_reference<decltype(complex)>::value ? "lvalue" : "rvalue") << endl;
	this->a_ = complex.getRe();
	this->b_ = complex.getIm();
}
