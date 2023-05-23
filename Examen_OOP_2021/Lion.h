#include "Feline.h"

class Lion : public Feline {
    int GetSpeed()
    {
        return 100;
    }
    std::string GetName() {
        return "Lion";
    }
    bool IsAFish()
    {
        return false;
    }
    bool IsABird()
    {
        return false;
    }
    bool IsAMammal()
    {
        return true;
    }
};