#include <iostream>
using namespace std;
class Complex3 {
private:
	double real;//复数实部
	double image;//复数虚部
public:
	Complex3(double real = 0.0, double image = 0.0) {//构造函数
		this->real = real;
		this->image = image;
	}
	void display() {
		cout << "(" << real << "," << image << ")" << endl;
	}
	Complex3 operator +(Complex3 B);//运算符+重载成员函数
	Complex3 operator=(Complex3 B);//运算符=重载成员函数
};
Complex3 Complex3::operator +(Complex3 B) {
	return Complex3(real + B.real, image + B.image);//创建一个临时对象作为返回值
}
Complex3 Complex3::operator =(Complex3 B) {
	real = B.real, image = B.image;
	cout << "operator=calling..." << endl;
	return *this;//return Complex3(real.image);
}
int main()
{
	Complex3 A3(100.0, 200.0), B3(-10.0, 20.0), C3;
	cout << "A3=";
	A3.display();
	cout << "B3=";
	B3.display();
	C3 = A3 + B3;//使用重载运算符完成复数加法
	cout << "C3=A3+B3=";
	C3.display();
	C3 = A3;
	cout << "C3=A3=";
	C3.display();
}