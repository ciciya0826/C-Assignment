#include <iostream>
using namespace std;

int add(int x, int y)
{
	cout << "(int, int)\t";
	return x + y;
}

double add(double x, double y)
{
	cout << "(double, double)\t";
	return x + y;
}

int add(int x, double y)
{
	cout << "(int, double)\t";
	return x + y;
}

double add(double x, int y)
{
	cout << "(double, int)\t";
	return x + y;
}

int main()
{
	cout << add(9, 8) << endl;
	cout << add(9.0, 8.0) << endl;
	cout << add(9, 8.0) << endl;
	cout << add(9.0, 8) << endl;
	return 0;
}