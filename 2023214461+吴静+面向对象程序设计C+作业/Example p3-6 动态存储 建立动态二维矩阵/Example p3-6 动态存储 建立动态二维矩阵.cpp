#include <iostream>
using namespace std;

int main()
{
	int m, n,i,j;
	cout << "请输入矩阵的行数m和列数n:" << endl;
	cin >> m >> n;
	int** dm;
	dm = new int* [m];	//先建立m个指针，存储m行
	for (int i = 0; i < m; i++)
		if ((dm[i] = new int [n]) == NULL)	//为每行分配m个空间
			exit(-1);

	//输入矩阵元素
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			cin >> dm[i][j];

	//输出矩阵元素
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			cout << dm[i][j] << "\t";
		cout << endl;
	}

	//释放空间
	for (i = 0; i < m; i++)
		delete[]dm[i];
	delete[]dm;

	return 0;
}