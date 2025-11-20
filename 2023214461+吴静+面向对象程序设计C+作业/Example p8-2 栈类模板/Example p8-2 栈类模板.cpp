#include <iostream>
using namespace std;
template <class T>
class Stack
{
private:
	int size;	//容量
	int top;	//栈顶元素的位置
	T* space;	//指向动态分配的内存空间，是模板类型T的指针，可以存储不同类型的数据
public:
	Stack(int = 10);	//构造函数声明，带有一个默认参数为10的整型参数
	~Stack()
	{
		delete[] space;
	}
	bool push(const T&);	//声明函数
	T pop();	//声明函数
	bool IsEmpty() const
	{
		return top == size;
	}
	bool IsFull() const
	{
		return top == 0;
	}
};
//模板类Stack的构造函数的定义
template <class T>
Stack <T>::Stack(int size)
{
	this->size = size;	//将传入的参数size赋值给类的成员变量size
	space = new T[size];
	top = size;	//初始位置
}
//模板类Stack中push函数的定义
template <class T>
bool Stack<T>::push(const T& element)
{
	if (!IsFull())
	{
		space[--top] = element;
		return true;
	}
	return false;
}
template <class T>
T Stack <T>::pop()
{
	return space[top++];
}
int main()
{
	Stack<char>S1(4);
	S1.push('x');
	S1.push('y');
	S1.push('z');
	S1.push('u');
	S1.push('v');
	while (!S1.IsEmpty())
		cout << S1.pop() << endl;
	return 0;
}