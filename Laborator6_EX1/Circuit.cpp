#include "Circuit.h"
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <typeinfo>
#include <iostream>
Circuit::Circuit() {}
Circuit::~Circuit()
{
	this->circuitCars.erase(circuitCars.begin(), circuitCars.end());
	this->circuitCars.shrink_to_fit();
}


double calculateCarFinishTime(Car* car, double circuitLenght);
bool canFinishTheRace(Car* car, double circuitLenght);
double calculateWeatherEfficienty(Car* car);

void ClearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X * csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR)' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

void Circuit::SetLength(double _circuitLength)
{
	this->circuitLength = _circuitLength;
}

void Circuit::SetWeather(Weather _weatherCondition)
{
	this->weatherCondition = _weatherCondition;
}

void Circuit::AddCar(Car* _circuitCar)
{
	this->circuitCars.push_back(_circuitCar);
	delete[] this->circuitCarsFinishTime;
	this->circuitCarsFinishTime = new double[this->circuitCars.size()];
}





const char* tempLine = "_____________________________________\
______________________________________________________________";
void Circuit::Race()
{
	for (int i = 0; i <= 200; i++)
	{
		for (int j = 0; j < circuitCars.size(); j++)
		{
			char* raceProgress = new char[101];
			strcpy(raceProgress, tempLine);
			raceProgress[99] = '#';
			raceProgress[0] = '>';
			auto firstLetter = circuitCars[j]->getCarType();
			auto position = int(circuitCars[j]->getAverageSpeed() * (i / 100.0));
			if (position >= 100)
				position = 99;
			raceProgress[position] = firstLetter[0];
			raceProgress[100] = '\0';
			printf("%s\n", raceProgress);


		}



		printf("\n");
		printf("Frame: %d", i);

		Sleep(15);
		if(i != 200)
		ClearScreen();
		
	}
	Sleep(2000);
	ClearScreen();






	for (int i = 0; i < circuitCars.size(); i++)
	{
		auto finishTime = calculateCarFinishTime(circuitCars[i], this->circuitLength);
		this->circuitCarsFinishTime[i] = finishTime;
	}
}

void Circuit::ShowFinalRanks()
{
	for(int i = 0; i < circuitCars.size()-1; i++)
		for (int j = i + 1; j < circuitCars.size(); j++)
		{
			if (this->circuitCarsFinishTime[i] > this->circuitCarsFinishTime[j])
			{
				std::swap(this->circuitCarsFinishTime[i], this->circuitCarsFinishTime[j]);
				std::swap(this->circuitCars[i], this->circuitCars[j]);
			}
		}
	for (int i = 0; i < circuitCars.size(); i++)
	{
		if (canFinishTheRace(circuitCars[i], this->circuitLength))
			printf("%s got %d place finishing in: %f units of time.\n", this->circuitCars[i]->getCarType(), i, this->circuitCarsFinishTime[i]*10);
	}
}

void Circuit::ShowWhoDidNotFinish()
{
	for (int i = 0; i < circuitCars.size(); i++)
	{
		if (!canFinishTheRace(circuitCars[i], this->circuitLength))
			printf("%s didn't finish the circuit. No fuel.\n", this->circuitCars[i]->getCarType());
	}
}


double calculateCarFinishTime(Car* car, double circuitLenght)
{
	if (!canFinishTheRace(car, circuitLenght))
		return -1;

	return (circuitLenght / (car->getAverageSpeed() * calculateWeatherEfficienty(car)));
}

bool canFinishTheRace(Car* car, double circuitLenght)
{
	double maxLenght = ((car->getFuelCapacity() / car->getFuelConsumption() * car->getAverageSpeed()) * calculateWeatherEfficienty(car));
	if (maxLenght > circuitLenght)
		return true;
	return false;
}




double calculateWeatherEfficienty(Car* car)
{
	
	auto weatherCondition = car->getWeatherEfficienty();
	if (weatherCondition == Weather::Sunny)
	{
		return 1.1f;
	}

	if (weatherCondition == Weather::Snowy)
	{
		return 0.6f;
	}

	if (weatherCondition == Weather::Rainy)
	{
		return 0.8f;
	}
}