#include "Student.h"
#include <cstring>


Student::Student(const char _name[], float _Mathematics, float _English, float _History)
{
	strcpy_s(this->name, _name);
	this->Mathematics = _Mathematics;
	this->English = _English;
	this->History = _History;
}


void Student::SetName(char _value[])
{
	strcpy_s(this->name, _value);
}

char* Student::GetName()
{
	return this->name;
}



float Student::GetGradeMath()
{
	return this->Mathematics;
}
float Student::GetGradeEnglish()
{
	return this->English;
}
float Student::GetGradeHistory()
{
	return this->History;
}

void Student::SetGradeMath(float _value)
{
	if (_value < 1 || _value > 10)
		return;

	this->Mathematics = _value;

}
void Student::SetGradeEnglish(float _value) {
	if (_value < 1 || _value > 10)
		return;

	this->English = _value;
}
void Student::SetGradeHistory(float _value)
{
	if (_value < 1 || _value > 10)
		return;

	this->History = _value;
}

float Student::GetAverageGrade()
{
	return 1.0 * (this->Mathematics + this->History + this->English) / 3;
}