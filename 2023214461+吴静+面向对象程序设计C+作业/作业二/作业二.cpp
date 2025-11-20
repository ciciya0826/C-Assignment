#include <iostream>
using namespace std;

class Matrix
{
private:
    int** matrix;    //二维动态数组
    int rows;    //行数
    int cols;    //列数

public:
    //构造函数
    Matrix(int r, int c) :rows(r), cols(c)
    {
        matrix = new int* [rows];    //为指向每行的指针分配内存
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new int[cols];    //为每一行分配cols个整数的空间
            for (int j = 0; j < cols; j++)
                matrix[i][j] = 0;
        }
    }
    
    //设置矩阵元素的值
    void setvalue(int row, int col, int value)
    {
        if (row >= 0 && row < rows && col >= 0 && col < cols)
            matrix[row][col] = value;
    }
    //获取矩阵元素的值
    int getvalue(int row, int col)
    {
        if (row >= 0 && row < rows && col >= 0 && col < cols)
            return matrix[row][col];
        else
            return 0;
    }
    //矩阵相加
    Matrix add(Matrix& other)
    {
        if (rows != other.rows || cols != other.cols)
        {
            cout << "两个相加的矩阵的行数和列数必须相同。输入不合法。" << endl;
            return Matrix(0, 0);
        }
        Matrix result(rows, cols);//这里结束的时候会掉用析构函数
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];    //对应位置元素相加
        return result;    //返回相加后的结果矩阵
    }
    //矩阵相乘
    Matrix multiply(Matrix& other)
    {
        if (cols != other.rows)
        {
            cout << "两个相乘的矩阵，前面的矩阵的列数应该等于后面的矩阵的行数。输入不合法。" << endl;
            return Matrix(0, 0);
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < other.cols; j++)
            {
                int sum = 0;
                for (int k = 0; k < cols; k++)
                    sum += matrix[i][k] * other.matrix[k][j];
                result.matrix[i][j] = sum;
            }
        return result;
    }
    //输出矩阵
    void printmatrix()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
                cout << getvalue(i, j) << " ";
            cout << endl;
        }
    }
};

int main()
{
    Matrix matrix1(2, 3);
    matrix1.setvalue(0, 0, 1);
    matrix1.setvalue(0, 1, 2);
    matrix1.setvalue(0, 2, 3);
    matrix1.setvalue(1, 0, 4);
    matrix1.setvalue(1, 1, 5);
    matrix1.setvalue(1, 2, 6);

    Matrix matrix2(2, 3);
    matrix2.setvalue(0, 0, 7);
    matrix2.setvalue(0, 1, 8);
    matrix2.setvalue(0, 2, 9);
    matrix2.setvalue(1, 0, 10);
    matrix2.setvalue(1, 1, 11);
    matrix2.setvalue(1, 2, 12);

    Matrix summatrix = matrix1.add(matrix2);
    cout << "matrix1 + matrix2 =" << endl;
    summatrix.printmatrix();

    Matrix matrix3(3, 2);
    matrix3.setvalue(0, 0, 1);
    matrix3.setvalue(0, 1, 2);
    matrix3.setvalue(1, 0, 3);
    matrix3.setvalue(1, 1, 4);
    matrix3.setvalue(2, 0, 5);
    matrix3.setvalue(2, 1, 6);

    Matrix multiplematrix = matrix1.multiply(matrix3);
    cout << "matrix1 * matrix3 =" << endl;
    multiplematrix.printmatrix();
}