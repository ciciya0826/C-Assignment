#include <iostream>
using namespace std;
enum city{Beijing,Shanghai,Tianjin=6,Chongqing};

int main()
{
	int n;
	cout << "Input a city number(" << Beijing - 1 << "to exit):" << endl;
	cin >> n;
	while (n >= Beijing)
	{
		switch (n)
		{
		case Beijing:cout << "Beijing" << endl;		break;
		case Shanghai:cout << "Shanghai" << endl;	break;
		case Tianjin:cout << "Tianjin" << endl;		break;
		case Chongqing:cout << "Chongqing" << endl;	break;
		default:cout << "无效的城市数字！" << endl;	break;
		}
		cin >> n;
	}
	return 0;
}