//
// Created by chinez on 5/23/2023.
//

#include "Cow.h"

std::string Cow::GetName() {
    return "Cow";
}

bool Cow::IsAFish()
{
    return false;
}
bool Cow::IsABird()
{
    return false;
}
bool Cow::IsAMammal()
{
    return true;
}
