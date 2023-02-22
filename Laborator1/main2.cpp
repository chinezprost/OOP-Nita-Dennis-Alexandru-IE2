#include <iostream>
#include <stdio.h>
#include <cstring>
#include <list>
using namespace std;

char proposition[256];
list<string> words;
list<string>::iterator it;

char *p;

bool sort_bySizeAlphabetical(const string& first, const string& second)
{
    unsigned i = 0;
    if(first.length() != second.length())
        return first.length() > second.length();

    while(i < first.length() && i < second.length())
    {
        if(tolower(first[i]) < tolower(second[i]))
            return true;
        if(tolower(first[i]) > tolower(second[i]))
            return false;
        ++i;
    }







}

int main()
{
    scanf("%[^\n]s", proposition);
    p = strtok(proposition, " ");
    while(p != nullptr)
    {
        words.emplace_back(p);
        p = strtok(nullptr, " ");
    }
    words.sort(sort_bySizeAlphabetical);
    for(it = words.begin(); it != words.end(); ++it)
    {
        cout << *it << '\n';
    }


}