#include <iostream>
using namespace std;
class piont6 {
private:
	int X, Y;
public:
	piont6(int X = 0, int Y = 0) {
		this->X = X, this->Y = Y;
	}
	double area() {//求面积
		return 0.0;
	}
};
const double PI = 3.14159;
class Circle6 :public piont6 {
private:
	double radius;//半径w
public:
	Circle6(int X, int Y, double R) :piont6(X, Y) {
		radius = R;
	}
	double area() {//求面积
		return PI * radius * radius;
	}
};
int main()
{
	piont6 P16(10, 10);
	cout << "P16.area()=" << P16.area() << endl;
	Circle6 C16(10, 10, 20);
	cout << "C16.area()=" << C16.area() << endl;
	piont6* Pp6;
	Pp6 = &C16;
	cout << "Pp6->area()=" << Pp6->area() << endl;
	piont6& Rp6 = C16;
	cout << "Rp6.area()=" << Rp6.area() << endl;
}