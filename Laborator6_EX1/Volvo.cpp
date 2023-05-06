#include "Volvo.h"

Volvo::Volvo() : Car(50, 7, 85) {}
Volvo::Volvo(double _fC, double _fCo, double _aS) : Car(_fC, _fCo, _aS) {}

double Volvo::getFuelCapacity()
{
	return this->fuelCapacity;
}

double Volvo::getFuelConsumption()
{
	return this->fuelConsumption;
}

double Volvo::getAverageSpeed()
{
	return this->averageSpeed;
}

const char* Volvo::getCarType()
{
	return this->carType;
}

double Volvo::getWeatherEfficienty()
{
	return this->harshWaterEfficienty;
}



