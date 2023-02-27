#pragma once
class Student
{
private:
	char name[255] = "\0";
	struct Grades
	{
		float Mathematics = -1;
		float English = -1;
		float History = -1;
	}grades;

public:
	void SetName(char value[]);
	char* GetName();

	float GetGradeMath();
	float GetGradeEnglish();
	float GetGradeHistory();

	void SetGradeMath(float _value);
	void SetGradeEnglish(float _value);
	void SetGradeHistory(float _value);

	float GetAverageGrade();

};