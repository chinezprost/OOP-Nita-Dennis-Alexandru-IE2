#include <string>
#include <iostream>
#include <queue>
#include <map>
#include <cstring>

class Comparator {
public:
    bool operator()(std::pair<std::string, int> a, std::pair<std::string, int> b)
    {
        if(a.second < b.second)
        {
            return true;
        }

        if(a.second == b.second)
        {
            if(a.first >= b.first)
                return true;
            else
                return false;
        }

        if(a.second > b.second)
        {
            return false;
        }
    }
};




std::string phrase;
std::map<std::string, int> words;
bool compare();
std::priority_queue<std::pair<std::string, int>, std::deque<std::pair<std::string, int>>, Comparator> sortedWords;


int i, j;
bool isSeparator(char value)
{
    if(value == ' ' || value == ',' || value == '?' || value == '!' || value == '.')
        return true;
    return false;
}



void insertToMap(std::string value)
{
    bool found = false;
    std::map<std::string, int>::iterator it = words.begin();
    while(it != words.end())
    {
        if(value.compare(it->first))
        {
            words[value]++;
            found = true;
            break;
        }
        it++;
    }
    if(!found)
    {
        words.insert({value, 1});
    }



}

int main()
{
    //std::getline(std::cin, phrase);
    phrase = "I bought an apple. Then I eat an apple. Apple is my favorite.";
    for(int i = 0; i < phrase.size(); i++)
        phrase[i] = std::tolower(phrase[i]);
    std::string aux = "";
    while(phrase[i] != '\0')
    {
        if(!isSeparator(phrase[i]))
        {
            aux += phrase[i];
        } else {
            if(!aux.empty())
                insertToMap(aux);
            aux = "";
        }
        i++;
    }



    for(auto it = words.begin(); it != words.end(); it++)
        sortedWords.emplace(std::make_pair(it->first, it->second));

    while(!sortedWords.empty())
    {
        auto foundPair = sortedWords.top();
        std::cout << foundPair.first << " => " << foundPair.second << '\n';
        sortedWords.pop();
    }
}