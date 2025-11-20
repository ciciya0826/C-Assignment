#include <iostream>
using namespace std;

class Clock
{
private:
    int H, M, S;
public:
    // 构造函数，若调用时不传参数则初始化为0时0分0秒
    Clock(int h = 0, int m = 0, int s = 0)
    {
        H = h, M = m, S = s;
        cout << "constructor:" << H << ":" << M << ":" << S << endl;
    }

    // 析构函数，在对象销毁时被调用，输出当前对象的时间信息，用于观察对象销毁情况
    ~Clock()
    {
        cout << "destructor:" << H << ":" << M << ":" << S << endl;
    }

    // 拷贝构造函数，用于以已有Clock对象初始化新的Clock对象
    // 在函数内部先输出拷贝前新对象成员变量的情况（初始未赋值时为未定义值）
    // 然后进行成员变量的拷贝赋值，实现对象的拷贝
    Clock(Clock& p)
    {
        cout << "copy constructor,before call:" << H << ":" << M << ":" << S << endl;
        H = p.H;
        M = p.M;
        S = p.S;
    }

    void ShowTime()
    {
        cout << H << ":" << M << ":" << S << endl;
    }
};

Clock fun(Clock C)
{
    return C;
}

int main()
{
    Clock C1(8, 0, 0);
    Clock C2(9, 0, 0);
    Clock C3(C1);   //copy一次。C3初建立时H,M,S都没有初始化
    fun(C2);    //copy两次
    /*调用fun函数时，在栈中为形参建立一个临时形参对象，实参与形参结合的过程相当于用实参对象初始化新建立的该临时形参对象，临时形参对象的拷贝构造函数被调用
    return C时将C的值复制给临时返回对象，用一次临时形参对象的拷贝构造函数*/
    Clock C4;
    C4 = C2;    //赋值，无拷贝，用一个对象的值去覆盖另一个对象的值
    return 0;
}

/*
constructor:8:0:0
constructor:9:0:0
copy constructor,before call:-858993460:-858993460:-858993460       Clock C3(C1)
copy constructor,before call:0:0:-1175593040            fun(C2)
copy constructor,before call:32762:-275297479:32759     fun(C2)
destructor:9:0:0        fun(C2)调用结束时，临时形参对象消失，析构函数被调用
destructor:9:0:0        fun临时返回对象消失，析构函数被调用
constructor:0:0:0       Clock(C4)
destructor:9:0:0        以下为对C4,C3,C2,C1依次调用析构函数
destructor:8:0:0
destructor:9:0:0
destructor:8:0:0
*/