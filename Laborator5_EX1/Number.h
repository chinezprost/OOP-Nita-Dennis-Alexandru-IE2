#pragma once
#define CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cstdio>
#include <algorithm>
class Number
{
private:
    int base;
    char* value = nullptr;
public:
    Number(const char* _value, int _base);
    Number(int _value);
    Number(const char* _value);
    Number(const Number& _source);
    Number(Number&& _source);
    ~Number();

    Number& operator -- (int);
    Number& operator -- ();

    bool operator == (const Number& number);
    bool operator >= (const Number& number);
    bool operator > (const Number& number);
    bool operator < (const Number& number);
    bool operator <= (const Number& number);
    void operator += (const Number& number);

    char operator[] (int);

    friend Number operator + (const Number& member, const Number& number);
    friend Number operator - (const Number& member, const Number& number);

    Number& operator = (const Number& number);
    Number& operator = (int intValue);
    Number& operator = (const char* stringValue);




    void SwitchBase(int newBase);
    void Print();
    int GetDigitsCount();
    int GetBase();

};