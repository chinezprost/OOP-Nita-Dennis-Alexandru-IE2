#pragma once
#include <fstream>
#include <vector>

class CsvIterator {
private:
    std::vector<std::string> *p;
public:
    CsvIterator(std::vector<std::string>* p);
    bool operator!=(const CsvIterator& _it);
    CsvIterator operator++();
    std::vector<std::string> operator*();
};

