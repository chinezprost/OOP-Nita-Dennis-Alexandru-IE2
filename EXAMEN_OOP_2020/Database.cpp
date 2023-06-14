#include "Database.h"

Database &Database::operator+=(Entry *value)
{
    this->entries.emplace_back(value);
    return *this;
}

Database &Database::operator -= (const std::string& value) {
    int position = 0;
    for(auto &entry : entries)
    {
        position += 1;
        if(entry->GetName().compare(value) == 0)
        {
            this->entries.erase(entries.begin()+position-1);
            this->entries.shrink_to_fit();
        }
    }
    return *this;
}

Entry **Database::begin() {
    return &this->entries[0];
}

Entry **Database::end() {
    return &this->entries[this->entries.size()];
}

void Database::Print() {
    for(auto &e : entries)
    {
        e->Print();
    }
    printf("\n");
}
