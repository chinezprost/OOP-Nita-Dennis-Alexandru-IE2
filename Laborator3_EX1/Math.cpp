#include "Math.h"
#include <stdarg.h>
#include <cstdlib>
#include <cstring>



int Math::Add(int a, int b)
{
	return a + b;
}

int Math::Add(int a, int b, int c)
{
	return a + b + c;
}

int Math::Add(double a, double b)
{
	return float(a + b);
}

int Math::Add(double a, double b, double c)
{
	return float(a + b + c);
}

int Math::Mul(int a, int b)
{
	return a * b;
}

int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}

int Math::Mul(double a, double b)
{
	return float(a * b);
}

int Math::Mul(double a, double b, double c)
{
	return float(a * b * c);
}

int Math::Add(int count, ...)
{
	int sum = 0;
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; i++)
	{
		auto aux = va_arg(args, int);
		sum += aux;
	}
	va_end(args);
	return sum;
}

char* Math::Add(const char* a, const char* b)
{
	if (a == nullptr || b == nullptr)
		return nullptr;
	int carry = 0;
	char* sum = (char*)malloc(1);
	sum[0] = '\n';
	if (a == nullptr || b == nullptr)
		return nullptr;
	long a_size = strlen(a) - 1;
	long b_size = strlen(b) - 1;
	long max_size = -1;
	max_size = (a_size > b_size) ? a_size : b_size;
	int current_position = 0;
	while (a_size >= 0 && b_size >= 0)
	{
		auto addition = a[a_size--] + b[b_size--] - 2 * '0';
		sum = (char*)realloc(sum, ++current_position * sizeof(char));
		memmove(sum + 1, sum, current_position);
		if (carry != 0)
			sum[0] = 1;
		else
			sum[0] = 0;
		carry = 0;
		sum[0] += addition % 10 + '0';
		if (addition > 9)
			carry++;
	}

	while (a_size >= 0)
	{
		memmove(sum + 1, sum, current_position++);
		if (carry != 0)
		{
			if (a[a_size] == '9')
			{
				a_size--;
				sum[0] = '0';
			}
			else
			{
				sum[0] = a[a_size--] + 1;
				carry = 0;
			}
		}
		sum[0] = a[a_size--];


	}

	while (b_size >= 0)
	{
		memmove(sum + 1, sum, current_position++);
		if (carry != 0)
		{
			if (b[b_size] == '9')
			{
				b_size--;
				sum[0] = '0';
			}
			else
			{
				sum[0] = a[b_size--] + 1;
				carry = 0;
			}
		}
		sum[0] = b[b_size--];
	}

	if (carry != 0)
	{
		memmove(sum + 1, sum, current_position);
		sum[0] = '1';
		sum[max_size + 2] = '\0';
	}
	else
		sum[max_size + 1] = '\0';

	return sum;
}