#include <fstream>
#include <iostream>
using namespace std;
int main()
{
	char name[8];
	float score;
	ifstream binfile;
	binfile.open("D:\\Desktop\\456.txt", ios:: binary);
	if (!binfile)
	{
		cerr << "123.txt open or create error!\n" << endl;
		exit(1);
	}
	while (!binfile.eof())
	{
		binfile.read(reinterpret_cast<char*>(name), 8 * sizeof(char));
		binfile.read(reinterpret_cast<char*>(&score), sizeof(float));
		cout << name << '\t' << score << endl;
	}
	binfile.close();
	return 0;
}