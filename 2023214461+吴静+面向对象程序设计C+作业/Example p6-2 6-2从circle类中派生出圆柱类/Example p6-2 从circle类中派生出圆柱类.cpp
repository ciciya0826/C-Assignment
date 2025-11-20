#include"Point2.h"
class Circle2 :protected Point2 {
protected:
	double radius;//半径
public:
	Circle2(double R, int X, int Y) :Point2(X, Y) {
		radius = R;
	}
	double area() {
		return PI * radius * radius;
	}
	void ShowCircle2() {
		cout << "Centre of circle:";
		ShowXY2();
		cout << "radius:" << radius << endl;
	}
};
class Cylinder :protected Circle2 {
private:
	double height;
public:
	Cylinder(int X, int Y, double R, double H) :Circle2(R, X, Y) {
		height = H;
	}
	double area() {
		return 2 * Circle2::area() + 2 * PI * radius * height;
	}
	double volume() {
		return Circle2::area() * height;
	}
	void ShowCylinder() {
		ShowCircle2();
		cout << "height of clinder:" << height << endl;
	}
};

int main()
{
	Cylinder CY(100, 200, 10, 50);
	CY.ShowCylinder();
	cout << "total area:" << CY.area() << endl;
	cout << "volume:" << CY.volume();
	return 0;
}