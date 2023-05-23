
#include "Animal.h"

class Shark : public Animal{
public:
    Shark() = default;
private:
    std::string GetName();
    bool IsAFish();
    bool IsABird();
    bool IsAMammal();
};