#include <vector>
#include "Entry.h"
#include "StringData.h"
#include "IntegerData.h"

class Database
{
private:
    std::vector<Entry*> entries;
public:
    Database& operator += (Entry* value);
    Database& operator -= (const std::string& value);
    Entry** begin();
    Entry** end();
    void Print();




};