#include "BMW.h"

BMW::BMW() : Car(200, 30, 100) {}
BMW::BMW(double _fC, double _fCo, double _aS) : Car(_fC, _fCo, _aS) {}

double BMW::getFuelCapacity()
{
	return this->fuelCapacity;
}

double BMW::getFuelConsumption()
{
	return this->fuelConsumption;
}

double BMW::getAverageSpeed()
{
	return this->averageSpeed;
}

const char* BMW::getCarType()
{
	return this->carType;
}

double BMW::getWeatherEfficienty()
{
	return this->harshWaterEfficienty;
}
