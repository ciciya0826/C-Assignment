#include<iostream>
#define PI 3.14
using namespace std;
class Point2 {
protected:
	int X, Y;
public:
	Point2(int X = 0, int Y = 0) {
		this->X = X;
		this->Y = Y;
	}
	void move(int OffX, int OffY) {
		X += OffX;
		Y += OffY;
	}
	void ShowXY2() {
		cout << "(" << X << "," << Y << ")" << endl;
	}
}; 
