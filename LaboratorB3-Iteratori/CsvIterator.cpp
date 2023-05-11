#include "CsvIterator.h"


CsvIterator::CsvIterator(std::vector<std::string>* _p) : p(_p) {}

bool CsvIterator::operator!=(const CsvIterator& _it)
{
    return this->p!=_it.p;
}

CsvIterator CsvIterator::operator++()
{
    this->p++;
    return *this;
}

std::vector<std::string> CsvIterator::operator*()
{
    return *this->p;
}
