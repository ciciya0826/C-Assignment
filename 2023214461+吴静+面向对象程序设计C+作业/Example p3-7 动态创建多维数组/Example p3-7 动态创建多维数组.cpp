#include <iostream>
using namespace std;

int main()
{
    float (*p)[3][4];    // 定义一个指向三维数组（数组大小为[3][4]）的指针p，该三维数组的元素类型为float
    int i, j, k;
    p = new float[2][3][4];    // 使用new动态分配一个三维数组的内存空间，这个三维数组的维度是[2][3][4]，并将其首地址赋给指针p
    //输入
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 4; k++)
            {
                // 通过指针p来访问三维数组中的每个元素，并按照一定的计算规则（i * 100 + j * 10 + k）为其赋值
                *(*(*(p + i) + j) + k) = i * 100 + j * 10 + k;
            }
        }
    }
    //输出
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 4; k++)
            {
                cout << p[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}