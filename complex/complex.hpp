#include <iostream>
class Complex{
public:
	Complex(float a, float b):a_(a), b_(b){}
	Complex() = delete;
	Complex(Complex& complex);
	Complex(Complex&& complex);
	void operator = (Complex& complex);
	void operator = (Complex&& complex);
	Complex operator + (Complex& complex);
	Complex operator - (Complex& complex);
	Complex operator * (Complex& complex);
	Complex operator / (Complex& complex);
	float getRe() const {
	return a_;
	}
	float getIm() const {
		return b_;
	}

private:
	float a_, b_;
};

