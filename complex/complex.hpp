#include <iostream>
class Complex{
public:
	Complex(float a, float b):a_(a), b_(b){}
	Complex() = delete;
	Complex(Complex& complex);
	Complex(Complex&& complex);
	void operator = (Complex& complex);
	void operator = (Complex&& complex);

	template<typename T>
	void print(const T &t) {
		std::cout << t << std::endl;
	}
	template<typename T, typename... Args>
	void print(const T &t, const Args&... args) {
		std::cout << t << "," << std::endl;
		print(args...);
	}
	float getRe() const {
	return a_;
	}
	float getIm() const {
		return b_;
	}

private:
	float a_, b_;
};

