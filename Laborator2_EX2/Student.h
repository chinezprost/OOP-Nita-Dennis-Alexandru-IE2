#pragma once
class Student
{
private:
	char name[25];
	
	float Mathematics = -1;
	float English = -1;
	float History = -1;
	

public:
	Student(const char _name[], float _Mathematics, float _English, float _History);
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