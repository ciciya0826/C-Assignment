#include <iostream>
using namespace std;

void make2D(int**& dm, int m, int n) {
	dm = new int* [m];
	for (int i = 0; i < m; i++) {
		if ((dm[i] = new int[n]) == NULL) {
			cout << "错误，退出。";
			exit(0);
		}
	}
}
void make2D(double**& dm, int m, int n) {
	dm = new double* [m];
	for (int i = 0; i < m; i++) {
		if ((dm[i] = new double[n]) == NULL) {
			cout << "错误，退出。";
			exit(0);
		}
	}
}

void input2D(int** dm, int m, int n) {
	cout << endl << "请为数组输入" << m * n << "个数字:";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> dm[i][j];
		}
	}
}
void input2D(double** dm, int m, int n) {
	cout << endl << "请为数组输入" << m * n << "个数字:";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> dm[i][j];
		}
	}
}

void output2D(int** dm, int m, int n) {
	cout << endl << "得到数组：" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << dm[i][j] << " , ";
		}
		cout << endl;
	}
}
void output2D(double** dm, int m, int n) {
	cout << endl << "该数组：" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << dm[i][j] << " , ";
		}
		cout << endl;
	}
}

void delete2D(int**& dm, int m, int n) {
	for (int i = 0; i < m; i++) {
		delete[] dm[i];
	}
	delete[] dm;
}
void delete2D(double**& dm, int m, int n) {
	for (int i = 0; i < m; i++) {
		delete[] dm[i];
	}
	delete[] dm;
}

void sq2D(int** dm1, int m1, int n1, int** dm2, int m2, int n2,
	int**& dm3, int& m3, int& n3)
{
	if (n1 != m2) {
		cout << endl << "错误，无法相乘。" << endl;
		return;
	}

	m3 = m1; n3 = n2;
	make2D(dm3, m3, n3);

	for (int i = 0; i < m1; i++) {
		for (int j = 0; j < n2; j++) {
			dm3[i][j] = 0;
			for (int a = 0; a < n1; a++) {
				dm3[i][j] += dm1[i][a] * dm2[a][j];
			}
		}
	}
}
void sq2D(double** dm1, int m1, int n1, double** dm2, int m2, int n2,
	double**& dm3, int& m3, int& n3)
{
	if (n1 != m2) {
		cout << endl << "错误，无法相乘。" << endl;
		return;
	}

	m3 = m1; n3 = n2;
	make2D(dm3, m3, n3);

	for (int i = 0; i < m1; i++) {
		for (int j = 0; j < n2; j++) {
			dm3[i][j] = 0;
			for (int a = 0; a < n1; a++) {
				dm3[i][j] += dm1[i][a] * dm2[a][j];
			}
		}
	}
}