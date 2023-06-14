//
// Created by chinez on 6/14/2023.
//

#include "IntegerData.h"

IntegerData::IntegerData(const std::string &name, const std::string &value) : Entry(name) {
    this->value = std::atoi(value.c_str());
}

void IntegerData::Add(const std::string &toAdd) {
    this->value += std::atoi(toAdd.c_str());
}

bool IntegerData::Substract(const int &toSubstract) {
    this->value -= toSubstract;
    return true;
}

void IntegerData::Print() {
    printf("%s = %d;", this->name.c_str(), this->value);
}
