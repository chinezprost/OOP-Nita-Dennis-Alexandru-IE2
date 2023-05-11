#pragma once
#include "Weather.h"
#include "Car.h"
#include <vector>
class Circuit
{
private:
	double circuitLength;
	std::vector<Car*> circuitCars;
	double* circuitCarsFinishTime;
	Weather weatherCondition;
public:


	Circuit();
	~Circuit();
	void SetLength(double _circuitLength);
	void SetWeather(Weather _weatherCondition);
	Weather GetWeather();
	void AddCar(Car* _circuitCar);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();

};

