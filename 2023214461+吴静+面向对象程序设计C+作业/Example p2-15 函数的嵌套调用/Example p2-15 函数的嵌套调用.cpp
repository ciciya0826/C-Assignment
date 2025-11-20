//求三个数中最大值和最小值的差值
#include <iostream>
using namespace std;

int max(int x, int y, int z)
{
	int t;
	t = x > y ? x : y;
	return(t > z ? t : z);
}

int min(int x, int y, int z)
{
	int t;
	t = x < y ? x : y;
	return(t < z ? t : z);
}

int dif(int x, int y, int z)
{
	return max(x, y, z) - min(x, y, z);
}

int main()
{
	int a, b, c;
	cout << "请分别输入a,b,c的值:" << endl;
	cin >> a >> b >> c;
	cout << "max-min=" << dif(a, b, c)<< endl;
	return 0;
}