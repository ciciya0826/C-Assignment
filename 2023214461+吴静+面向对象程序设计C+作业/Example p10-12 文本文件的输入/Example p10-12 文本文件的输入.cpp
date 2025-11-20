#include <fstream>
#include <iostream>
using namespace std;
int main()
{
	char name[8], score[6];
	ifstream txtfile;	//创建一个ifstream类型的对象txtfile
	txtfile.open("D:\\Desktop\\123.txt");	//以输入模式打开
	if (!txtfile)
	{
		cerr << "123.txt open error!" << endl;
		exit(1);
	}
	while(!txtfile.eof())	//当文件达到末尾，eof表示end of file
	{
		txtfile >> name >> score;	//从已打开的文件中按空格等空白字符分隔，依次读取数据到name和score中
		cout << name << '\t' << score << endl;
	}
	txtfile.close();
	return 0;
}