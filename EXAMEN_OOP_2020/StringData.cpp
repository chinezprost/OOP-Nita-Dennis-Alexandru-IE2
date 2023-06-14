//
// Created by chinez on 6/14/2023.
//

#include "StringData.h"

StringData::StringData(const std::string &name, const std::string &value) : Entry(name) {
    this->value = value;
}

void StringData::Add(const std::string &toAdd) {
    this->value += toAdd;
}

bool StringData::Substract(const int &toSubstract) {
    if(toSubstract > this->value.size())
    {
        printf("StringData: len(%s) < %d\n", this->value.c_str(), toSubstract);
        return false;
    }
    this->value.erase(this->value.size()-toSubstract, toSubstract);
    return true;
}

void StringData::Print() {
    printf("%s = %s;", this->name.c_str(), this->value.c_str());
}
