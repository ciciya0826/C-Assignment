#include <iostream>
using namespace std;
#include "hanshushengming.h"

int main() {
	double** dm1, ** dm2, ** dm3;
	int m1, n1, m2, n2, m3, n3;

	cout << "输入第一个数组的大小m,n：";
	cin >> m1 >> n1;
	make2D(dm1, m1, n1);
	input2D(dm1, m1, n1);
	output2D(dm1, m1, n1);

	cout << "输入第二个数组的大小m,n：";
	cin >> m2 >> n2;
	make2D(dm2, m2, n2);
	input2D(dm2, m2, n2);
	output2D(dm2, m2, n2);

	cout << endl << "进行矩阵乘法" << endl;

	sq2D(dm1, m1, n1, dm2, m2, n2, dm3, m3, n3);

	output2D(dm3, m3, n3);

	delete2D(dm1, m1, n1);
	delete2D(dm2, m2, n2);
	delete2D(dm3, m3, n3);
	return 0;
}