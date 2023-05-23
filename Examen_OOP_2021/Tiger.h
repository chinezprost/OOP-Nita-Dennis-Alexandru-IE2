#include "Feline.h"

class Tiger : public Feline {
    int GetSpeed()
    {
        return 100;
    }
    std::string GetName() {
        return "Tiger";
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