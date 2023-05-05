#include "CsvReader.h"

CsvReader::CsvReader(std::ifstream &_stream) : stream(&_stream)
{
    std::string auxiliaryString;
    std::string readedLine;
    std::vector<std::string> lineVector;
    while(std::getline(*this->stream, readedLine))
    {

        bool delimiterBypass = false;
        int index = 0;
        while(readedLine[index] != '\0')
        {
            if(readedLine[index] == '"')
            {
                delimiterBypass = !delimiterBypass;
            }
            if(readedLine[index] != ',' || delimiterBypass)
            {
                auxiliaryString += readedLine[index];
            }
            else
            {
                lineVector.emplace_back(auxiliaryString);
                auxiliaryString.clear();
            }
            index += 1;
        }
        lineVector.emplace_back(auxiliaryString);
        auxiliaryString.clear();
        this->memory[this->size++] = lineVector;
        lineVector.clear();
    }
}
