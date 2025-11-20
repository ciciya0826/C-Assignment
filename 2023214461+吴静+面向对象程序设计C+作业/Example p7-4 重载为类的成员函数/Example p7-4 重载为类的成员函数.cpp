#include <iostream>
using namespace std;
class Complex4 {
private:
	double real;
	double image;
public:
	Complex4(double real = 0.0, double image = 0.0) {//构造函数
		this->image = image;
		this->real = real;
	}
	void display() {
		cout << "(" << real << "," << image << ")" << endl;
	}
};
class PComplex4 {//复数指针类定义
private:
	Complex4* PC;
public:
	PComplex4(Complex4* PC = NULL) {
		this->PC = PC;
	}
	Complex4* operator->() {
		static Complex4 NullComplex4(0, 0);//避免指针为空
		if (PC == NULL) {
			return &NullComplex4;
		}
		return PC;
	}
};
int main()
{
	PComplex4 P14;//指针未初始化
	P14->display();//显示预先定义的（0，0）
	Complex4 C14(100, 200);
	P14 = &C14;
	P14->display();//显示有效数据
}