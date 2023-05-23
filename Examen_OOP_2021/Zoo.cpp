//
// Created by chinez on 5/23/2023.
//
#include "Zoo.h"

std::vector<Animal *> Zoo::GetFishes()
{
    std::vector<Animal*> animalContainer;
    for(auto animal : this->animals)
    {
        if(animal->IsAFish())
        {
            animalContainer.emplace_back(animal);
        }
    }
    return animalContainer;
}

std::vector<Animal *> Zoo::GetBirds()
{
    std::vector<Animal*> animalContainer;
    for(auto animal : this->animals)
    {
        if(animal->IsABird())
        {
            animalContainer.emplace_back(animal);
        }
    }
    return animalContainer;
}

std::vector<Animal *> Zoo::GetMammals()
{
    std::vector<Animal*> animalContainer;
    for(auto animal : this->animals)
    {
        if(animal->IsAMammal())
        {
            animalContainer.emplace_back(animal);
        }
    }
    return animalContainer;
}

std::vector<Feline *> Zoo::GetFelines()
{
    std::vector<Feline*> animalContainer;
    for(auto animal : this->animals)
    {
        if(animal->GetName() == "Lion" || animal->GetName() == "Tiger")
        {
            animalContainer.emplace_back(reinterpret_cast<Feline*>(animal));
        }
    }
    return animalContainer;
}

int Zoo::GetTotalAnimals()
{
    return this->animals.size();
}

void Zoo::operator+=(Animal* animal)
{
    this->animals.emplace_back(animal);
}

bool Zoo::operator()(std::string name)
{
    for(auto animal : this->animals)
    {
        if(animal->GetName() == name)
        {
            return true;
        }
    }
    return false;
}

