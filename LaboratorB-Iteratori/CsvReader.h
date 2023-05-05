#pragma once
#include "CsvIterator.h"
#include <fstream>
#include <vector>

class CsvReader {
private:
    std::ifstream *stream;
    std::vector<std::string> *memory = new std::vector<std::string>[100];
    int size = 0;
public:
    explicit CsvReader(std::ifstream &_stream);

    CsvIterator begin()
    {
        return {memory};
    }

    CsvIterator end()
    {
        return {memory+size};
    }
};
