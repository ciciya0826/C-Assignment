#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    char line[180];     //用于临时存储从标准输入读取的数据
    fstream myfile;     //fstream类型的对象myfile，可用于进行文件的读写等操作
    //ios::out表示以输出模式打开，ios::trunc表示若文件已存在则清空
    myfile.open("D:\\Desktop\\123.txt", ios::out | ios::trunc);  //以输出模式打开指定路径下的文件
    if (!myfile)    //如果文件打开失败
    {
        cerr << "File open or create error!" << endl;
        exit(1);
    }
    while (cin >> line)
        myfile << line;     //将输入的字符串写入到已打开的文件中
    myfile.close();
    return 0;
}