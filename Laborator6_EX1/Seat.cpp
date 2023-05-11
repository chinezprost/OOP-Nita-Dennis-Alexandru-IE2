#include "Seat.h"

Seat::Seat() : Car(50, 20, 90) {}
Seat::Seat(double _fC, double _fCo, double _aS) : Car(_fC, _fCo, _aS) {}

double Seat::getFuelCapacity()
{
	return this->fuelCapacity;
}

double Seat::getFuelConsumption()
{
	return this->fuelConsumption;
}

double Seat::getAverageSpeed()
{
	return this->averageSpeed;
}

const char* Seat::getCarType()
{
	return this->carType;
}

double Seat::getWeatherEfficienty()
{
	return this->harshWaterEfficienty;
}


