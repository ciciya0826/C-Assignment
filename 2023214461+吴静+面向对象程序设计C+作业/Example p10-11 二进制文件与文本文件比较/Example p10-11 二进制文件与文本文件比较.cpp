#include <fstream>
#include <iostream>
using namespace std;
int main()
{
	const char* name[3] = { "Antony","John","Tom" };
	float score[3] = { 85.5,90,60 };
	fstream txtfile, binfile;	//创建两个fstream类型的对象，txtfile用于文本文件的读写，binfile用于二进制文件的读写
	txtfile.open("D:\\Desktop\\123.txt", ios::out | ios::trunc);
	binfile.open("D:\\Desktop\\456.txt", ios::binary | ios::out | ios::trunc);
	if (!txtfile)
	{
		cerr << "123.txt open or create error!\n" << endl;
		exit(1);
	}
	if (!binfile)
	{
		cerr << "123.txt open or create error!\n" << endl;
		exit(1);
	}
	for (int i = 0; i < 3; i++)
	{
		txtfile << name[i] << '\t' << score[i] << endl;	//写入文本文件
		binfile.write(name[i], 8 * sizeof(char));	//第二个参数表示写入的字节数
		binfile.write((char *)&score[i], sizeof(float));
	}
	txtfile.close();
	binfile.close();
	return 0;
}