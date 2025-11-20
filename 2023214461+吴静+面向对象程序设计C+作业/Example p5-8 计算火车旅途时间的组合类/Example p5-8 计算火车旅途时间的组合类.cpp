#include <iostream>
using namespace std;
class Clockc {
private:
	int H, M, S;
public:
	Clockc(int h = 0, int m = 0, int s = 0) {
		H = h, M = m, S = s;
		cout << "constructor:" << H << ":" << M << ":" << S << endl;
	}
	~Clockc() {
		cout << "destructor:" << H << ":" << M << ":" << S << endl;
	}
	int GetH() {
		return H;
	}
	int GetM() {
		return M;
	}
	int GetS() {
		return S;
	}
	void SetTime(int H, int M, int S) {
		this->H = H, this->M = M, this->S = S;
	}
}
class TrainTrip {
private:
	const char* TrainNo;//车次
	Clockc StartTime;//出发时间
	Clockc EndTime;//到达时间
public:
	TrainTrip(const char* TrainNo, Clockc S, Clockc E) {
		this->TrainNo = TrainNo;
		StartTime = S;
		EndTime = E;
	}
	Clockc TripTime() {
		int tH, tM, tS;//临时存储小时、分、秒数
		int carry = 0;//借位
		Clockc tTime;//临时存储时间
		(tS = EndTime.GetS() - StartTime.GetS()) > 0 ? carry = 0 : tS += 60, carry = 1;
		(tM = EndTime.GetM() - StartTime.GetM()) > 0 ? carry = 0 : tM += 60, carry = 1;
		(tH = EndTime.GetH() - StartTime.GetH()) > 0 ? carry = 0 : tH += 24;
		tTime.SetTime(tH, tM, tS);
		return tTime;
	}
};
int main()
{
	cout << "P5_8:" << endl;
	Clockc C13(8, 10, 10), C23(6, 1, 2);//定义Clockc类的对象
	Clockc C33;//定义Clockc类对象，存储结果
	TrainTrip T1("K16", C13, C23);//定义TrainTrip对象
	C33 = T1.TripTime();
	C33.ShowTime();
}