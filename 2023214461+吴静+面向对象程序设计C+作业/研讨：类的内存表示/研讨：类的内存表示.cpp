#include <iostream>
using namespace std;

class A
{
    int m1, m2;
    static int S;
public:
    void fun()
    {
        cout << "m1 address: " << &m1 << endl;
        cout << "m2 address: " << &m2 << endl;
        cout << "S address: " << &S << endl;
    }
};

int A::S = 0;

void main()
{
    A* pa = new A;
    A a1, a2;

    cout << "a1 address: " << &a1 << endl;
    a1.fun();
    cout << "a1.fun address: " << &A::fun << endl;

    cout << "a2 address: " << &a2 << endl;
    a2.fun();
    cout << "a2.fun address: " << &A::fun << endl;
}