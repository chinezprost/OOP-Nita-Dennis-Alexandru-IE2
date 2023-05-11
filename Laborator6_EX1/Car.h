#pragma once
#include <cstring>
#include <string>

class Car
{
protected:
	Car(double _fC, double _fCo, double _aS) : fuelCapacity(_fC), fuelConsumption(_fCo), averageSpeed(_aS) {};
	double fuelCapacity = 0;
	double fuelConsumption = 0;
	double averageSpeed = 0;
	double harshWaterEfficienty = 1;
public:
	virtual double getFuelCapacity() = 0;
	virtual double getFuelConsumption() = 0;
	virtual double getAverageSpeed() = 0;
	virtual double getWeatherEfficienty() = 0;  
	virtual const char* getCarType() = 0;
};