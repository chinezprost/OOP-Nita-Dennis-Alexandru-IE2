#include "Student.h"
#include <cstring>


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
	return this->grades.Mathematics;
}
float Student::GetGradeEnglish()
{
	return this->grades.English;
}
float Student::GetGradeHistory()
{
	return this->grades.History;
}

void Student::SetGradeMath(float _value)
{
	if (_value < 1 || _value > 10)
		return;

	grades.Mathematics = _value;

}
void Student::SetGradeEnglish(float _value) {
	if (_value < 1 || _value > 10)
		return;

	grades.English = _value;
}
void Student::SetGradeHistory(float _value)
{
	if (_value < 1 || _value > 10)
		return;

	grades.History = _value;
}

float Student::GetAverageGrade()
{
	return 1.0 * (
		this->grades.Mathematics +
		this->grades.History +
		this->grades.English) / 3;
}