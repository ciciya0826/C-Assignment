#include <iostream>

class A  // 定义一个名为A的类
{
    int m1, m2;  // 私有成员变量，默认访问权限为private，只能在类内访问
    static int S;  // 私有静态成员变量，默认访问权限为private，需在类外初始化
public:
    void fun() {}  // 公有成员函数，可以通过类的对象在类外调用
};

int A::S = 0;  // 在类外初始化静态成员变量S

int main()
{
    A* pa = new A;
    A a1, a2;

    // 输出非静态成员变量m1和m2的地址
    std::cout << "a1.m1 address: " << &a1.m1 << std::endl;
    std::cout << "a1.m2 address: " << &a1.m2 << std::endl;

    // 输出静态成员变量S的地址
    std::cout << "A::S address: " << &A::S << std::endl;

    // 输出成员函数fun的地址
    std::cout << "a1.fun address: " << &A::fun << std::endl;

    // 尝试访问私有成员变量（错误示范，编译会报错）
    // a1.m1 = 10;  // 错误，m1是私有成员变量，不能在类外直接访问
    // a1.m2 = 20;  // 错误，m2是私有成员变量，不能在类外直接访问

    // 正确调用公有成员函数
    a1.fun();

    return 0;
}