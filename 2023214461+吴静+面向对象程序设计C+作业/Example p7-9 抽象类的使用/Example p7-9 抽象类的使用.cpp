#include <iostream>
using namespace std;
class Shape {
public:
	virtual double area()const = 0;
	virtual void show() = 0;
};
class Point9 :public Shape {
protected:
	int X, Y;
public:
	Point9(int X = 0, int Y = 0) {
		this->X = X, this->Y = Y;
	}
	void show() {
		cout << "(" << X << "," << Y << ")" << endl;
	}
	double area()const {
		return 0.0;
	}
};
class Circle9 :public Point9 {
protected:
	double radius;
public:
	Circle9(int X, int Y, double R) :Point9(X, Y) {
		radius = R;
	}
	double area()const {
		return 3.14 * radius * radius;
	}
	void show() {
		cout << "Centre:" << "(" << X << "," << Y << ")" << endl;
		cout << "radius:" << radius << endl;
	}
};
class Cylinder :public Circle9 {
private:
	double height;
public:
	Cylinder(int X, int Y, double R, double H) :Circle9(X, Y, R) {
		height = H;
	}
	double area()const {
		return 2 * Circle9::area() + 2 * 3.14 * radius * height;
	}
	void show() {
		Circle9::show();
		cout << "height of cylinder:" << height << endl;
	}
};
int main()
{
	Cylinder CY9(100, 200, 10, 50);
	Shape* P9;
	P9 = &CY9;
	P9->show();
	cout << "total area:" << P9->area() << endl;
	Circle9 Cir9(5, 10, 100);
	Shape& R9 = Cir9;
	R9.show();

	return 0;
}
