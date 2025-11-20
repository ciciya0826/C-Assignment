#include<iostream>
using namespace std;
class Complex {
private:
	double real;//复数实部
	double image;//复数虚部
public:
	Complex(double real = 0.0, double image = 0.0) {//构造函数
		this->real = real;
		this->image = image;
	}
	void display() {
		cout << "(" << real << "," << image << ")" << endl;
	}
	friend Complex operator +(Complex A, Complex B) {//重载+为友元函数
		return Complex(A.real + B.real, A.image + B.image);
	}
	friend Complex operator -(Complex A, Complex B);//重载-为友元函数
	friend Complex operator -(Complex A);
	friend Complex operator ++(Complex& A);//重载前置++为友元函数
	friend Complex operator ++(Complex& A, int);//重载后置++为友元函数
};
Complex operator -(Complex A, Complex B) {//重载运算符-的实现函数
	return Complex(A.real - B.real, A.image - B.image);
}
Complex operator -(Complex A) {//重载运算符-（取负）的函数实现
	return Complex(-A.real, -A.image);
}
Complex operator ++(Complex& A) {//重载运算符前置++的函数实现
	return Complex(++A.real, A.image);
}
Complex operator ++(Complex& A, int) {//重载运算符后置++的函数实现
	return Complex(A.real++, A.image);
}

int main()
{
	Complex A(100.0, 200.0), B(-10.0, 20.0), C;
	cout << "A=", A.display();
	cout << "B=", B.display();
	C = A + B;//使用重载运算符完成复数加法
	cout << "C=A+B", C.display();
	C = A - B;//使用重载运算符实现复数减法
	cout << "C=A-B=", C.display();
	C = -A + B;
	cout << "C=-A+B=", C.display();
	C = A++;
	cout << "C=A++,C=", C.display();
	C = ++A;
	cout << "C=++A,C=", C.display();
	C = A + 5;
	C.display();
}