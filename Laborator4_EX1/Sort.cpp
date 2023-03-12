#include "Sort.h"
#define _CRT_SECURE_NO_WARNINGS


Sort::Sort(int _numberCount, int _min, int _max)
{
	std::random_device randomDevice;
	std::mt19937 gen(randomDevice());
	std::uniform_int_distribution<> distr(_min, _max);

	for (int i = 1; i <= _numberCount; i++)
	{
		auto generatedNumber = distr(gen);
		this->container.emplace_back(generatedNumber);
	}

}

Sort::Sort(std::list<int> _inputContainer) : container(_inputContainer) {}

Sort::Sort(int* _inputVector, int _inputVectorElementCount)
{
	for (int i = 1; i <= _inputVectorElementCount; i++)
	{
		this->container.emplace_back(_inputVector[i - 1]);
	}
}

Sort::Sort(int _count, ...)
{
	va_list args;
	va_start(args, _count);
	for (int i = 1; i <= _count; i++)
	{
		this->container.emplace_back(va_arg(args, int));
	}
	va_end(args);
}

Sort::Sort(const char* _inputString)
{
	char* _newString = new char[strlen(_inputString)];
	strcpy(_newString, _inputString);
	char* p = strtok(_newString, ",");
	while (p != nullptr)
	{
		//convert to int
		int exponent = 1, numberToBePushed = 0;
		for (int i = strlen(p) - 1; i >= 0; i--)
		{
			numberToBePushed = exponent * (p[i] - '0');
			exponent = exponent * 10;
		}
		this->container.emplace_back(numberToBePushed);
		p = strtok(NULL, ",");
	}
}

void Sort::Print()
{
	std::list<int>::iterator it;
	for (it = this->container.begin(); std::next(it,1) != this->container.end(); it++)
	{
	
		printf("%d, ", *it);
	}
	printf("%d", *it);
	printf("\n");
}

std::list<int>::iterator Sort::GetElementFromIndex(int index)
{
	std::list<int>::iterator list_front = this->container.begin();
	std::advance(list_front, index);
	return list_front;

}

void Sort::InsertSort(bool ascendent)
{
	if (!ascendent)
	{
		int i, sortKey, j;
		for (i = 1; i < this->GetElementsCount(); i++)
		{
			sortKey = *this->GetElementFromIndex(i);
			j = i - 1;

			while (j >= 0 && *this->GetElementFromIndex(j) < sortKey)
			{
				*this->GetElementFromIndex(j + 1) = *this->GetElementFromIndex(j);
				j--;
			}
			*this->GetElementFromIndex(j + 1) = sortKey;
		}
	}
	else
	{
		int i, sortKey, j;
		for (i = 1; i < this->GetElementsCount(); i++)
		{
			sortKey = *this->GetElementFromIndex(i);
			j = i - 1;

			while (j >= 0 && *this->GetElementFromIndex(j) > sortKey)
			{
				*this->GetElementFromIndex(j + 1) = *this->GetElementFromIndex(j);
				j--;
			}
			*this->GetElementFromIndex(j + 1) = sortKey;
		}
	}
}

void Sort::BubbleSort(bool ascendent)
{
	int containerSize = this->container.size();
	if (!ascendent)
	{
		for (int i = 0; i < containerSize; i++)
		{
			for (int j = 0; j < containerSize - i - 1; j++)
			{
				auto value1 = this->GetElementFromIndex(j);
				auto value2 = this->GetElementFromIndex(j + 1);
				if (*value1 < *value2)
				{
					std::swap(*value1, *value2);
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < containerSize; i++)
		{
			for (int j = 0; j < containerSize - i - 1; j++)
			{
				auto value1 = this->GetElementFromIndex(j);
				auto value2 = this->GetElementFromIndex(j + 1);
				if (*value1 > *value2)
				{
					std::swap(*value1, *value2);
				}
			}
		}
	}
}

void Sort::QuickSort(int listStart, int listEnd, bool ascendent)
{
	if (!ascendent)
	{
		while (listStart < listEnd)
		{
			//partition algorithm
			int containerPivot = *this->GetElementFromIndex(listStart);
			int count = 0;
			for (int i = listStart + 1; i <= listEnd; i++)
			{
				if (*this->GetElementFromIndex(i) <= containerPivot)
					count++;

			}
			int containerPivotIndex = listStart + count;
			if (containerPivotIndex == listStart)
				return;
			std::swap(*this->GetElementFromIndex(containerPivotIndex), *this->GetElementFromIndex(listStart));

			int i = listStart, j = listEnd;

			while (i < containerPivotIndex && j > containerPivotIndex)
			{
				while (*this->GetElementFromIndex(i) > containerPivot)
					i++;

				while (*this->GetElementFromIndex(j) <= containerPivot)
					j--;

				if (i < containerPivotIndex && j > containerPivotIndex)
				{
					std::swap(*this->GetElementFromIndex(i), *this->GetElementFromIndex(j));
					i++; j--;
				}
			}

			Sort::QuickSort(listStart, containerPivotIndex - 1);
			Sort::QuickSort(containerPivotIndex + 1, listEnd);
		}
	}
	else
	{
		while (listStart < listEnd)
		{
			//partition algorithm
			int containerPivot = *this->GetElementFromIndex(listStart);
			int count = 0;
			for (int i = listStart + 1; i <= listEnd; i++)
			{
				if (*this->GetElementFromIndex(i) <= containerPivot)
					count++;

			}
			int containerPivotIndex = listStart + count;
			if (containerPivotIndex == listStart)
				return;
			std::swap(*this->GetElementFromIndex(containerPivotIndex), *this->GetElementFromIndex(listStart));

			int i = listStart, j = listEnd;

			while (i < containerPivotIndex && j > containerPivotIndex)
			{
				while (*this->GetElementFromIndex(i) <= containerPivot)
					i++;

				while (*this->GetElementFromIndex(j) > containerPivot)
					j--;

				if (i < containerPivotIndex && j > containerPivotIndex)
				{
					std::swap(*this->GetElementFromIndex(i), *this->GetElementFromIndex(j));
					i++; j--;
				}
			}

			Sort::QuickSort(listStart, containerPivotIndex - 1);
			Sort::QuickSort(containerPivotIndex + 1, listEnd);
		}
	}
	


}

int Sort::GetElementsCount()
{
	return this->container.size();
}


