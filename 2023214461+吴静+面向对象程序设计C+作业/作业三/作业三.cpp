#include <iostream>
using namespace std;

class CMatrix2D
{
private:
	int** matrix;
	int rows;
	int cols;
public:
	//默认构造函数，创建初始为空的矩阵
	CMatrix2D()
	{
		rows = 0;
		cols = 0;
		matrix = NULL;
	}
	//带参数的构造函数，创建指定行和列的矩阵
	CMatrix2D(int m, int n)
	{
		rows = m;
		cols = n;
		Make2DArray();	//调用函数分配内存
	}
	//拷贝构造函数
	CMatrix2D(const CMatrix2D& other)
	{
		rows = other.rows;
		cols = other.cols;
		Make2DArray();
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				matrix[i][j] = other.matrix[i][j];
	}
	//析构函数
	~CMatrix2D()
	{
		Delete2DArray();
	}
	//分配内存
	void Make2DArray()
	{
		matrix = new int* [rows];	//先分配行指针数组
		for (int i = 0; i < rows; i++)
			matrix[i] = new int[cols];
	}
	//释放内存
	void Delete2DArray()
	{
		if (matrix != NULL)
		{
			for (int i = 0; i < rows; i++)
				delete[] matrix[i];
			delete[] matrix;
			matrix = NULL;
		}
	}
	//输入
	void Input()
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				cin >> matrix[i][j];
	}
	//输出
	void Output()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
				cout << matrix[i][j] << " ";
			cout << endl;
		}
	}
	//成员函数实现矩阵加法运算符重载
	CMatrix2D operator+(const CMatrix2D& other)
	{
		if (rows != other.rows || cols != other.cols)
		{
			cout << "不合法，无法相加！" << endl;
			return CMatrix2D();
		}
		CMatrix2D result(rows, cols);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
		return result;
	}
	//声明友元函数
	friend CMatrix2D operator+(const CMatrix2D& left, const CMatrix2D& right);
};

CMatrix2D operator+(const CMatrix2D& left, const CMatrix2D& right)
{
	if (left.rows != right.rows || left.cols != right.cols)
	{
		cout << "不合法，无法相加！" << endl;
		return CMatrix2D();
	}
	CMatrix2D result(left.rows, left.cols);
	for (int i = 0; i < left.rows; i++)
		for (int j = 0; j < left.cols; j++)
			result.matrix[i][j] = left.matrix[i][j] + right.matrix[i][j];
	return result;
}

int main()
{
	int m, n;
	cout << "请输入矩阵的行数和列数:";
	cin >> m >> n;
	CMatrix2D A(m, n);
	CMatrix2D B(m, n);
	cout << "请输入矩阵A的元素:" << endl;
	A.Input();
	cout << "请输入矩阵B的元素:" << endl;
	B.Input();
	CMatrix2D C = A+B;
	cout << "两矩阵相加的结果为:" << endl;
	C.Output();
	return 0;
}