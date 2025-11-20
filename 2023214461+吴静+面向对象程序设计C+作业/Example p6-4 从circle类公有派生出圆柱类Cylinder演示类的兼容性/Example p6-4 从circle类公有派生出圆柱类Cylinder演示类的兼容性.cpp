#include<iostream>
#include "Circle.h"
using namespace std;

class Cylinder2 :public Circle {
private:
	double height;
public:
	Cylinder2(int X, int Y, double R, double H) :Circle(R, X, Y) {
		height = H;
	}
	void ShowCylinder2() {
		ShowCircle();
		cout << "height of clinder:" << height << endl;
	}
};

int main()
{
	Point P(1, 1);
	Circle Cir4(15, 20, 20);
	Cylinder2 CY4(15, 300, 300, 50);
	Point* Pp;
	Pp = &P;
	Pp->ShowXY();
	Pp = &Cir4;
	Pp->ShowXY();
	Pp = &CY4;
	Pp->ShowXY();
	Circle& RC = CY4;
	RC.ShowXY();
	P = Cir4;
	P.ShowXY();
}