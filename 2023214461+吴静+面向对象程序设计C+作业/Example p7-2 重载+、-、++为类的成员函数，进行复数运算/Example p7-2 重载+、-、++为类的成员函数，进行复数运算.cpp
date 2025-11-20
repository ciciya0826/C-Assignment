#include <iostream>
using namespace std;
class Complex2 {
private:
	double real;//复数实部
	double image;//复数虚部
public:
	Complex2(double real = 0.0, double image = 0.0) {//构造函数
		this->real = real;
		this->image = image;
	}
	void display() {
		cout << "(" << real << "," << image << ")" << endl;
	}
	Complex2 operator +(Complex2 B);//运算符+重载成员函数
	Complex2 operator -(Complex2 B);//运算符-重载成员函数
	Complex2 operator -();//运算符-（取负）重载成员函数
	Complex2 operator ++();//前置++重载成员函数
	Complex2 operator ++(int);//后置++重载成员函数
};
Complex2 Complex2::operator +(Complex2 B) {//重载运算符+的实现函数
	return Complex2(real + B.real, image + B.image);
}
Complex2 Complex2::operator -(Complex2 B) {//重载运算符-的实现函数
	return Complex2(real - B.real, image - B.image);
}
Complex2 Complex2::operator -() {//重载运算符-（取负）的函数实现
	return Complex2(-real, -image);
}
Complex2 Complex2::operator ++() {//重载运算符前置++的函数实现
	return Complex2(++real, image);
}
Complex2 Complex2::operator ++(int) {//重载运算符后置++的函数实现
	return Complex2(real++, image);
}
int main()
{
	Complex2 A2(100.0, 200.0), B2(-10.0, 20.0), C2;
	cout << "A2=", A2.display();
	cout << "B2=", B2.display();
	C2 = A2 + B2;
	cout << "C2=A+B", C2.display();
	C2 = A2 - B2;
	cout << "C2=A2-B2=", C2.display();
	C2 = -A2 + B2;
	cout << "C2=-A+B=", C2.display();
	C2 = A2++;
	cout << "C2=A2++,C2=", C2.display();
	C2 = ++A2;
	cout << "C2=++A2,C2=", C2.display();
	C2 = A2 + 5;
	C2.display();
}