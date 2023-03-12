#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <cstdlib>
#include <list>
#include <random>
#include <stdarg.h>
#include <cstring>
#include <algorithm>

class Sort
{
private:
    std::list<int> container;
public:
    Sort(int _numberCount, int _min, int _max);
    Sort(std::list<int> _inputContainer);
    Sort(int* _inputVector, int _inputVectorElementCount);
    Sort(int _count, ...);
    Sort(const char* _inputString);
    void InsertSort(bool ascendent = false);
    void QuickSort(int listStart, int p, bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();

    int GetElementsCount();
    std::list<int>::iterator GetElementFromIndex(int index);
};