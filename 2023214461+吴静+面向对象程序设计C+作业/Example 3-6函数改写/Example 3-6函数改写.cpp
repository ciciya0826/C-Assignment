#include <iostream>
using namespace std;
void Make2DArray(int**& dm, int& m, int& n)
{
	cout << "请输入矩阵的大小m,n:";
	cin >> m >> n;
	dm = new int* [m];
	for (int i = 0; i < m; i++)
		if ((dm[i] = new int[n]) == NULL)
		{
			cout << "构造矩阵失败。"<<endl;
			exit(-1);
		}
}
void Input2DArray(int**& dm, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		cout << "请输入第" << i << "行的元素" ;
		for (int j = 0; j < n; j++)
			cin >> dm[i][j];
	}
}
void Output2DArray(int**& dm, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for(int j=0;j<n;j++)
			cout << dm[i][j] << "\t";
		cout << endl;
	}
}
void Delete2DArray(int**& dm, int m, int n)
{
	for (int i = 0; i < m; i++)
		delete[]dm[i];
	delete[]dm;
}

int main()
{
	int m, n;
	int** dm;
	Make2DArray(dm, m, n);
	Input2DArray(dm, m, n);
	cout << "矩阵元素为:" << endl;
	Output2DArray(dm, m, n);
	Delete2DArray(dm, m, n);
	return 0;
}