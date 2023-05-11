#include "RangeRover.h"

RangeRover::RangeRover() : Car(40, 11, 70) {}
RangeRover::RangeRover(double _fC, double _fCo, double _aS) : Car(_fC, _fCo, _aS) {}

double RangeRover::getFuelCapacity()
{
	return this->fuelCapacity;
}

double RangeRover::getFuelConsumption()
{
	return this->fuelConsumption;
}

double RangeRover::getAverageSpeed()
{
	return this->averageSpeed;
}

const char* RangeRover::getCarType()
{
	return this->carType;
}

double RangeRover::getWeatherEfficienty()
{
	return this->harshWaterEfficienty;
}

