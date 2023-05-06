#pragma once
#include "Car.h"
class Volvo : public Car
{
private:
	const char* carType = "Volvo";

public:
	Volvo();
	Volvo(double _fC, double _fCo, double _aS);

	double getFuelCapacity();
	double getFuelConsumption();
	double getAverageSpeed();
	const char* getCarType();
	double getWeatherEfficienty();

};

