#include "Entry.h"

class IntegerData : public Entry {
private:
    int value;
public:
    IntegerData(const std::string& name, const std::string& value);
    void Add(const std::string& toAdd) override;
    bool Substract(const int& toSubstract) override;
    void Print() override;
};