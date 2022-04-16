#include <iostream>
using namespace std;

class Car
{
private:
	int gasolineGauge;

public:
	Car(int gas)
		:gasolineGauge(gas)
	{}

	int getGasGauge() const
	{
		return gasolineGauge;
	}
};

class HybridCar : public Car
{
private:
	int electricGauge;

public:
	HybridCar(Car &car,int gas)
		:Car(car.getGasGauge()),electricGauge(gas)
	{}

	int getElecGauge() const
	{
		return electricGauge;
	}
};

class HybridWaterCar :public HybridCar
{
private:
	int waterGauge;

public:
	HybridWaterCar(Car &car1,HybridCar &car2,int gas)
		:HybridCar(car1, car2.getElecGauge()), waterGauge(gas)
	{}

	void showCurrentGauge() const
	{
		cout << "ÀÜ¿© °¡¼Ö¸°: " << getGasGauge() << endl;
		cout << "ÀÜ¿© Àü±â·®: " << getElecGauge() << endl;
		cout << "ÀÜ¿© ¿öÅÍ·®: " << waterGauge << endl;
	}
};

int main()
{
	Car car(10);
	HybridCar hcar(car,20);
	HybridWaterCar hwcar(car,hcar,30);

	hwcar.showCurrentGauge();

	return 0;
}