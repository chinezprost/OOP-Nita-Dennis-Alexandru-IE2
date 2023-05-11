#include <iostream>
#include "Car.h"
#include "Circuit.h"
#include "Volvo.h"
#include "Fiat.h"
#include "RangeRover.h"
#include "Seat.h"
#include "BMW.h"

int main(void)
{
	Circuit c;
	c.SetLength(100);
	c.SetWeather(Weather(Rainy));
	c.AddCar(new Volvo());
	c.AddCar(new BMW());
	c.AddCar(new Seat());
	c.AddCar(new Fiat());
	c.AddCar(new RangeRover());
	c.Race();
	c.ShowFinalRanks();
	c.ShowWhoDidNotFinish();
	return 0;
}