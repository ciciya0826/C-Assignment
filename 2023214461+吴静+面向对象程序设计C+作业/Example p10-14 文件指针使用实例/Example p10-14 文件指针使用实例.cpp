#include <fstream>
#include <iostream>
using namespace std;
int main()
{
	char name1[8], name2[8];
	float score1, score2;
	int rec_num, rec_size, i;
	fstream binfile("D:\\Desktop\\456.txt", ios::out | ios::in | ios::binary);
	if (!binfile)
	{
		cerr << "123.txt open or create error!\n" << endl;
		exit(1);
	}
	rec_size = sizeof(float) + 8 * sizeof(char);
	binfile.seekg(0, ios::end);
	rec_num = binfile.tellg() / (rec_size);
	for (i = 0; i < rec_num / 2; i++)
	{
		binfile.seekg((long)i * rec_size, ios::beg);
		binfile.read((char*)name1, 8 * sizeof(char));
		binfile.read((char*)&score1, sizeof(float));
		binfile.seekg(-(long)(i + 1) * rec_size, ios::end);
		binfile.read
	}
}