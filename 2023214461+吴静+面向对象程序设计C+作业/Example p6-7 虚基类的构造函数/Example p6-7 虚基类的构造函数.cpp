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
class Car7 :virtual public Automoblie {//小客车类
private:
	int seat;
public:
	Car7(int power, int seat) :Automoblie(power) {
		this->seat = seat;
		cout << "Car constructing..." << endl;
	}
	void Show() {
		cout << "car:";
		Automoblie::Show();
		cout << " seat:" << seat << endl;
	}
};
class Wagon7 :virtual public Automoblie {
private:
	int load;
public:
	Wagon7(int power, int load) :Automoblie(power) {
		this->load = load;
		cout << "Wagon constructing..." << endl;
	}
	void Show() {
		cout << "wagon:";
		Automoblie::Show();
		cout << " load:" << load << endl;
	}
};
class StationWagon7 :public Car7, public Wagon7 {
public:
	StationWagon7(int CPower, int WPower, int seat, int load) :Automoblie(CPower), Wagon7(WPower, load), Car7(CPower, seat) {
		cout << "StationWagon7 constructing..." << endl;
	}
	void Show() {
		cout << "StationWagon7:" << endl;
		Car7::Show();
		Wagon7::Show();
	}
};

int main()
{
	StationWagon7 SW7(105, 108, 3, 8);
	SW7.Show();
	return 0;
}