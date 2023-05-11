#pragma once
#include "Car.h"
class Seat : public Car
{
private:
	const char* carType = "Seat";

public:
	Seat();
	Seat(double _fC, double _fCo, double _aS);

	double getFuelCapacity();
	double getFuelConsumption();
	double getAverageSpeed();
	const char* getCarType();
	double getWeatherEfficienty();

};
