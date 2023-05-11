#pragma once
#include "Car.h"
class RangeRover : public Car
{
private:
	const char* carType = "RangeRover";

public:
	RangeRover();
	RangeRover(double _fC, double _fCo, double _aS);

	double getFuelCapacity();
	double getFuelConsumption();
	double getAverageSpeed();
	const char* getCarType();
	double getWeatherEfficienty();


};
