#include "Number.h"
#define _CRT_SECURE_NO_WARNINGS


int baseFromValue(int value);
int valueFromBase(char c);
char* convertFromBase10(int value, int base);
int convertToBase10(char* value, int base);
int getNumberOfDigitsOfInt(int _value);

Number::Number(const char* _value, int _base)
{
	this->value = new char[strlen(_value) + 1];
	this->base = _base;
	strcpy(value, _value);
}

Number::Number(const char* _value)
{
	if (this->base == -1)
	{
		printf("Uninitialised base. Aborting... \n");
		return;
	}
	delete[] this->value;
	this->value = new char[strlen(_value) + 1];
	strcpy(this->value, _value);

}

Number::~Number()
{
	if (this->value == nullptr)
		return;
	delete[] this->value;
	this->value = nullptr;
}

void Number::SwitchBase(int newBase)
{
	if (this->base == newBase)
	{
		printf("Can not change the base into the same base. Aborting...\n");
		return;
	}

	char* newBaseValue = convertFromBase10(convertToBase10(this->value, this->base), newBase);
	if (newBaseValue == nullptr)
	{
		printf("Can not switch base. An error has occured.\n");
		return;
	}
	this->base = newBase;
	this->value = newBaseValue;

}

Number::Number(int _value) {
	auto valueNumberOfDigits = getNumberOfDigitsOfInt(_value);
	this->value = new char[valueNumberOfDigits + 1];
	this->base = 10;
	for (int i = valueNumberOfDigits-1; i >= 0; i--)
	{
		this->value[i] = (_value % 10) + '0';
		_value /= 10;
	}
	this->value[valueNumberOfDigits] = '\0';
}

Number::Number(const Number& _source)
{
	this->base = _source.base;
	this->value = new char[strlen(_source.value) + 1];
	strcpy(this->value, _source.value);
}



Number::Number(Number&& _source)
{
	this->base = _source.base;
	this->value = _source.value;
	_source.value = nullptr;
}

char Number::operator[] (int index)
{
	return this->value[index];
}

Number& Number::operator += (const Number& number)
{
	int initialBase = this->base;
	int value1 = convertToBase10(this->value, this->base);
	int value2 = convertToBase10(number.value, number.base);
	int returnValue = value1 + value2;
	this->value = convertFromBase10(returnValue, initialBase);
	return (*this);
}

bool Number::operator == (const Number& number)
{
	char* newValue = new char[100];
	strcpy(newValue, convertFromBase10(convertToBase10(number.value, number.base), this->base));
	if (strlen(this->value) == strlen(number.value))
	{
		delete[] newValue;
		return true;
	}
	delete[] newValue;
	return false;
}

bool Number::operator >= (const Number& number)
{
	char* newValue = new char[100];
	strcpy(newValue, convertFromBase10(convertToBase10(number.value, number.base), this->base));
	if (strlen(this->value) >= strlen(number.value))
	{
		delete[] newValue;
		return true;
	}
	else if (strlen(this->value) < strlen(number.value))
	{
		delete[] newValue;
		return false;
	}

	if (strcmp(this->value, newValue) >= 0)
	{
		delete[] newValue;
		return true;
	}
	else
	{
		delete[] newValue;
		return false;
	}
}

bool Number::operator > (const Number& number)
{
	char* newValue = new char[100];
	strcpy(newValue, convertFromBase10(convertToBase10(number.value, number.base), this->base));
	if (strlen(this->value) > strlen(number.value))
	{
		delete[] newValue;
		return true;
	}
	else if(strlen(this->value) < strlen(number.value))
	{
		delete[] newValue;
		return false;
	}

	if (strcmp(this->value, newValue) > 0)
	{
		delete[] newValue;
		return true;
	}
	else
	{
		delete[] newValue;
		return false;
	}

}

bool Number::operator < (const Number& number)
{
	char* newValue = new char[100];
	strcpy(newValue, convertFromBase10(convertToBase10(number.value, number.base), this->base));
	if (strlen(this->value) < strlen(number.value))
	{
		delete[] newValue;
		return true;
	}
	else if (strlen(this->value) > strlen(number.value))
	{
		delete[] newValue;
		return false;
	}

	if (strcmp(this->value, newValue) < 0)
	{
		delete[] newValue;
		return true;
	}
	else
	{
		delete[] newValue;
		return false;
	}
}

bool Number::operator <= (const Number& number)
{
	char* newValue = new char[100];
	strcpy(newValue, convertFromBase10(convertToBase10(number.value, number.base), this->base));
	if (strlen(this->value) <= strlen(number.value))
	{
		delete[] newValue;
		return true;
	}
	else if (strlen(this->value) > strlen(number.value))
	{
		delete[] newValue;
		return false;
	}

	if (strcmp(this->value, newValue) <= 0)
	{
		delete[] newValue;
		return true;
	}
	else
	{
		delete[] newValue;
		return false;
	}
}

Number& Number::operator--(int)
{
	this->value[strlen(value) - 1] = '\0';
	return (*this);
}

Number& Number::operator--()
{
	memmove(this->value, this->value + 1, strlen(this->value));
	return (*this);
}

Number& Number::operator = (const Number& number)
{
	this->base = number.base;
	this->value = new char[strlen(number.value) + 1];
	strcpy(this->value, number.value);
	return (*this);
}

Number& Number::operator = (const char* stringValue)
{
	delete[] this->value;
	this->value = new char[strlen(stringValue) + 1];
	strcpy(this->value, stringValue);
	return (*this);
}

Number& Number::operator = (int intValue)
{
	delete[] this->value;
	auto valueNumberOfDigits = getNumberOfDigitsOfInt(intValue);
	this->value = new char[valueNumberOfDigits + 1];
	this->base = 10;
	for (int i = valueNumberOfDigits-1; i >= 0; i--)
	{
		this->value[i] = (intValue % 10) + '0';
		intValue /= 10;
	}
	this->value[valueNumberOfDigits] = '\0';
	return (*this);
}

void Number::Print()
{
	for (int i = 0; i < strlen(this->value); i++)
		printf("%c", this->value[i]);
	printf("\n");
}

Number operator - (const Number& member, const Number& number)
{
	int maxBase = (member.base > number.base) ? member.base : number.base;
	int decimalValue1 = convertToBase10(member.value, member.base);
	int decimalValue2 = convertToBase10(number.value, number.base);

	decimalValue1 -= decimalValue2;
	auto newValue = convertFromBase10(decimalValue1, maxBase);
	return Number(newValue, maxBase);
}

Number operator + (const Number& member, const Number& number)
{
	int maxBase = (member.base > number.base) ? member.base : number.base;
	int decimalValue1 = convertToBase10(member.value, member.base);
	int decimalValue2 = convertToBase10(number.value, number.base);

	decimalValue1 += decimalValue2;
	char* newValue = convertFromBase10(decimalValue1, maxBase);
	return Number(newValue, maxBase);
}

int Number::GetBase()
{
	return this->base;
}

int Number::GetDigitsCount()
{
	return strlen(this->value);
}

int convertToBase10(char* value, int base)
{
	int length = strlen(value), exponent = 1, num = 0;

	for (int i = length - 1; i >= 0; i--)
	{
		if (valueFromBase(value[i]) >= base)
		{
			printf("Number is invalid. Aborting...\n");
			return -1;
		}

		num += valueFromBase(value[i]) * exponent;
		exponent *= base;
	}

	return num;
}
char* convertFromBase10(int value, int base)
{
	char* result = new char[100] {0};
	int count = 0;
	while (value > 0)
	{
		result[count++] = baseFromValue(value % base);
		value /= base;
	}
	result[count] = '\0';
	std::reverse(result, result + strlen(result));
	return result;
}

int valueFromBase(char c)
{
	if (c >= '0' && c <= '9')
		return (int)c - '0';
	else
		return (int)c - 'A' + 10;
}

int baseFromValue(int value)
{
	if (value >= 0 && value <= 9)
		return (char)(value + '0');
	else
		return (char)(value - 10 + 'A');
}

int getNumberOfDigitsOfInt(int value)
{
	unsigned int numberOfDigits = 0;
	do {
		++numberOfDigits;
		value /= 10;
	} while (value);

	return numberOfDigits;
}