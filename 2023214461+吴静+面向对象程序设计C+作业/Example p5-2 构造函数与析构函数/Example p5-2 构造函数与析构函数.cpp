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
		cout << "constructor:" << H << ":" << M << ":" << S << endl;
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

/*
运行结果为
constructor:8:0:0
constructor:9:0:0
constructor:10:0:0
constructor:11:0:0
destructor:11:0:0
destructor:10:0:0
destructor:9:0:0
destructor:8:0:0
*/

//局部对象在栈中建立，因此消失的顺序与建立的顺序相反