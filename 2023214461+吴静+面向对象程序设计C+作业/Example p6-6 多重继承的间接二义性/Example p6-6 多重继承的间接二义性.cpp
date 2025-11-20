#include <iostream>
using namespace std;
class Automoblie {//汽车类
private:
	int power;//动力
public:
	Automoblie(int power) {
		this->power = power;
	}
	void Show() {
		cout << "power:" << power;
	}
};
class Car6 :public Automoblie {//小客车类
private:
	int seat;
public:
	Car6(int power, int seat) :Automoblie(power) {
		this->seat = seat;
	}
	void Show() {
		cout << "car:";
		Automoblie::Show();
		cout << " seat:" << seat << endl;
	}
};
class Wagon6 :public Automoblie {
private:
	int load;
public:
	Wagon6(int power, int load) :Automoblie(power) {
		this->load = load;
	}
	void Show() {
		cout << "wagon:";
		Automoblie::Show();
		cout << " load:" << load << endl;
	}
};
class StationWagon6 :public Car6, public Wagon6 {
public:
	StationWagon6(int CPower, int WPower, int seat, int load) :Wagon6(WPower, load), Car6(CPower, seat) {
	}
	void Show() {
		cout << "StationWagon6:" << endl;
		Car6::Show();
		Wagon6::Show();
	}
};

int main()
{
	StationWagon6 SW6(105, 108, 3, 8);
	SW6.Show();
}