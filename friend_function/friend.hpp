class A{
private:
int num;
public:
A(int a) : num(a){}
int getA();
friend int fun(A&a);
};
void test_friend_function();