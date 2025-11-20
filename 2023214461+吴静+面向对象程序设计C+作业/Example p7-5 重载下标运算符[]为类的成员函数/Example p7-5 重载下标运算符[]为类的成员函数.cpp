#include <iostream>
using namespace std;
class String5 {
private:
	char* Str;
	int len;
public:
	void ShowStr() {
		cout << "string:" << Str << ",length:" << len << endl;
	}
	String5(const char* p = NULL) {
		if (p) {
			len = strlen(p);
			Str = new char[len + 1];
			strcpy_s(Str, len + 1, p);
		}
		else {
			len = 0;
			Str = NULL;
		}
	}
	~String5() {
		if (Str != NULL)
			delete[]Str;
	}
	char& operator[](int n) {//重载运算符[]，处理String5函数
		return *(Str + n);
	}
	const char& operator[](int n)const {//重载运算符[],处理const String5对象
		return *(Str + n);
	}
};
int main()
{
	String5 S15("0123456789abcdef");
	S15.ShowStr();
	S15[10] = 'A';
	cout << "after S15[10]=A" << endl;
	S15.ShowStr();
	const String5 S25("ABCDEFGHIJKLMN");
	cout << "S25[10]=" << S25[10] << endl;
}