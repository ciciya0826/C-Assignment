#include <iostream>
using namespace std;
class Clock
{
private:
	int H, M, S;
public:
	Clock(int h = 0, int m = 0, int s = 0)
	{
		H = h, M = m, S = s;
		cout << "constructor:" << H << ":" << S << endl;
	}
	~Clock()
	{
		cout << "destructor:" << H << ":" << M << ":" << S << endl;
	}
};
Clock C1(8, 0, 0);
Clock C2(9, 0, 0);
int main()
{
	Clock C3(10, 0, 0);
	Clock C4(11, 0, 0);
	return 0;
}