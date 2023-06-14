#pragma once
#include <string>

class Entry
{
protected:
    std::string name;
public:
    Entry(const std::string& name);
    std::string& GetName();
    virtual void Add(const std::string& toAdd) = 0;
    virtual bool Substract(const int& toSubstract) = 0;
    virtual void Print() = 0;
};