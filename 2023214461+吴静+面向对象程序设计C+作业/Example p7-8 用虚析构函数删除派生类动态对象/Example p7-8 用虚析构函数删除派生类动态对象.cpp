#include <iostream>
using namespace std;
class A8 {
public:
	virtual ~A8() {//虚析构函数
		cout << "A8::~A8()is called." << endl;
	}
	A8() {
		cout << "A8::A8()is called." << endl;
	}
};
class B8 :public A8 {
private:
	int* ip;
public:
	B8(int size = 0) {
		ip = new int[size];
		cout << "B8::B8()is called." << endl;
	}
	~B8() {
		cout << "B8::~B8()is called." << endl;
		delete[]ip;
	}
};
int main()
{
	A8* b8 = new B8(10);
	delete b8;
}