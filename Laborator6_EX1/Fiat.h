#pragma once
#include "Car.h"
class Fiat : public Car
{
private:
	const char* carType = "Fiat";

public:
	Fiat();
	Fiat(double _fC, double _fCo, double _aS);

	double getFuelCapacity();
	double getFuelConsumption();
	double getAverageSpeed();
	const char* getCarType();
	double getWeatherEfficienty();

};

