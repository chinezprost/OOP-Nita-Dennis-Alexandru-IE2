//
// Created by chinez on 6/14/2023.
//

#include "Entry.h"
#include "string"

Entry::Entry(const std::string& name)
{
    this->name = name;
}

std::string &Entry::GetName()
{
    return this->name;
}

