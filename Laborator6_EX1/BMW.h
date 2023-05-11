#pragma once
#include "Car.h"
class BMW : public Car
{
private:
	const char* carType = "BMW";

public:
	BMW();
	BMW(double _fC, double _fCo, double _aS);

	double getFuelCapacity();
	double getFuelConsumption();
	double getAverageSpeed();
	const char* getCarType();
	double getWeatherEfficienty();

};
