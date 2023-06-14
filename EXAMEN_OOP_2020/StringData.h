#include "Entry.h"

class StringData : public Entry {
private:
    std::string value;
public:
    StringData(const std::string& name, const std::string& value);
    void Add(const std::string& toAdd) override;
    bool Substract(const int& toSubstract) override;
    void Print() override;
};