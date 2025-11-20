#include<iostream>
using namespace std;

class Car {//小客车类
private:
	int power;
	int seat;
public:
	Car(int power, int seat) {
		this->power = power;
		this->seat = seat;
	}
	void Show() {
		cout << "car power:" << power << " seat:" << seat << endl;
	}
};
class Wagon {//小客车类
private:
	int power;
	int load;
public:
	Wagon(int power, int load) {
		this->load = load;
		this->power = power;
	}
	void Show() {
		cout << "wagon power:" << power << " load:" << load << endl;
	}
};
class StationWagon :public Car, public Wagon {//客货两用车类
public:
	StationWagon(int power, int seat, int load) :Wagon(power, load), Car(power, seat) {
	}
	void ShowSW() {
		cout << "StationWagon:" << endl;
		Car::Show();
		Wagon::Show();
	}
};

int main()
{
	StationWagon SW(105, 3, 8);
	/*SW.Show();*/    //错误，出现二义性
	SW.ShowSW();
}