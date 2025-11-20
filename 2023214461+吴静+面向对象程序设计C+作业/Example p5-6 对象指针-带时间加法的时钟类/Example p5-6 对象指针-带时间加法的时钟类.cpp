#include <iostream>
using namespace std;

class Clock
{
private:
    int H, M, S;  
public:
    void SetTime(int h, int m, int s)
    {
        H = h, M = m, S = s;  
    }
    void ShowTime()
    {
        cout << H << ":" << M << ":" << S << endl;  
    }
// 构造函数
    Clock(int h = 0, int m = 0, int s = 0)
    {
        H = h, M = m, S = s;  
    }
// 拷贝构造函数
    Clock(Clock& p)
    {
        H = p.H, M = p.M, S = p.S;  
    }

    // 函数声明
    void TimeAdd(Clock* Cp);
    void TimeAdd(int h, int m, int s);
    void TimeAdd(int s);
};

void Clock::TimeAdd(Clock* Cp)
{
    H = (Cp->H + H + (Cp->M + M + (Cp->S + S) / 60) / 60) % 24;
    M = (Cp->M + M + (Cp->S + S) / 60) % 60;
    S = (Cp->S + S) % 60;
}

void Clock::TimeAdd(int h, int m, int s)
{
    H = (h + H + (m + M + (s + S) / 60) / 60) % 24;
    M = (m + M + (s + S) / 60) % 60;
    S = (s + S) % 60;
}

void Clock::TimeAdd(int s)
{
    H = (H + (M + (S + s) / 60) / 60) % 24;
    M = (M + (S + s) / 60) % 60;
    S = (S + s) % 60;
}

int main()
{
    Clock C1;
    Clock C2(8, 20, 20);
    C1.TimeAdd(4000);
    C1.ShowTime();
    C2.TimeAdd(&C1);
    C2.ShowTime();

    return 0;
}