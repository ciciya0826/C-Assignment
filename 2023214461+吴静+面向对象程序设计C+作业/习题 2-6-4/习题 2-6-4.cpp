#include <iostream>
using namespace std;

int zhengshujiechen(int n)
{
	if (n > 1)
	{
		int sum = 1;
		sum = n * zhengshujiechen(n - 1);
		return sum;
	}
	else
		return 1;
}

long long changjiechen(int n)
{
	if (n > 1)
	{
		long long sum = 1;
		sum = n * changjiechen(n - 1);
		return sum;
	}
	else
		return 1;
}


int main()
{
    int n, i;
    cout << "Please input a number:";
    cin >> n;
	cout << n << "的阶乘为" << zhengshujiechen(n)<<endl;
	for(i=1;i<100;i++)
		if (zhengshujiechen(i) < zhengshujiechen(i-1))
		{
			cout << "当为int类型时溢出前的n为" << i - 1<<endl;
			break;
		}
	for (i = 1; i < 100; i++)
		if (changjiechen(i) < changjiechen(i - 1))
		{
			cout << "当为int类型时溢出前的n为" << i - 1 << endl;
			break;
		}
    return 0;
}