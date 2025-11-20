#include <iostream>
using namespace std;
class point7 {
private:
	int X, Y;
public:
	point7(int X = 0, int Y = 0) {
		this->X = X;
		this->Y = Y;
	}
	virtual double ara() {
		return 0.0;
	}
};
class Circle7 :public point7 {
private:
	double radius;
public:
	Circle7(int X, int Y, double R) :point7(X, Y) {
		radius = R;
	}
	double area() {
		return 3.14 * radius * radius;
	}
};
int main()
{
	point7 P17(10, 10);
	cout << "P17.area()=" << P17.ara() << endl;
	Circle7 C17(10, 10, 20);
	cout << "C17.area()=" << C17.area() << endl;
	point7* Pp7;
	Pp7 = &C17;
	cout << "Pp7->area()=" << Pp7->ara() << endl;
	point7& Rp7 = C17;
	cout << "Rp7.area()=" << Rp7.ara() << endl;
}