#include "Fiat.h"

Fiat::Fiat() : Car(20, 10, 40) {}
Fiat::Fiat(double _fC, double _fCo, double _aS) : Car(_fC, _fCo, _aS) {}

double Fiat::getFuelCapacity()
{
	return this->fuelCapacity;
}

double Fiat::getFuelConsumption()
{
	return this->fuelConsumption;
}

double Fiat::getAverageSpeed()
{
	return this->averageSpeed;
}

const char* Fiat::getCarType()
{
	return this->carType;
}

double Fiat::getWeatherEfficienty()
{
	return this->harshWaterEfficienty;
}
