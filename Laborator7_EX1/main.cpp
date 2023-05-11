#include <cstdio>

double operator"" _Kelvin(unsigned long long value)
{
	return (value - 273.15f);
}

double operator"" _Fahrenheit(unsigned long long value)
{
	return ((value + 32) / 1.8f);
}


int main()
{
	double a = 300_Kelvin;
	double b = 170_Fahrenheit;

	printf("%f\n", a);
	printf("%f\n", b);



	return 0;
}