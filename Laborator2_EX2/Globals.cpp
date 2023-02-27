#pragma once
#include "Student.h"
#include "Globals.h"
#include <cstring>

int CompareStudentMath(Student* first, Student* second)
{
	float _value1 = first->GetGradeMath();
	float _value2 = second->GetGradeMath();
	if (_value1 > _value2)
		return 1;
	if (_value1 < _value2)
		return -1;
	return 0;
}

int CompareStudentHistory(Student* first, Student* second)
{
	float _value1 = first->GetGradeHistory();
	float _value2 = second->GetGradeHistory();
	if (_value1 > _value2)
		return 1;
	if (_value1 < _value2)
		return -1;
	return 0;
}

int CompareStudentEnglish(Student* first, Student* second)
{
	float _value1 = first->GetGradeEnglish();
	float _value2 = second->GetGradeEnglish();
	if (_value1 > _value2)
		return 1;
	if (_value1 < _value2)
		return -1;
	return 0;
}

int CompareStudentAverageGrade(Student* first, Student* second)
{
	float _value1 = first->GetAverageGrade();
	float _value2 = second->GetAverageGrade();
	if (_value1 > _value2)
		return 1;
	if (_value1 < _value2)
		return -1;
	return 0;
}

int CompareStudentName(Student* first, Student* second)
{
	char* _value1 = first->GetName();
	char* _value2 = second->GetName();

	if (strcmp(_value1, _value2) > 0)
		return 1;
	if (strcmp(_value1, _value2) < 0)
		return -1;
	return 0;
}