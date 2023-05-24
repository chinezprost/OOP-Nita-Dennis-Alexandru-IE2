// Problema rezolvă următoarea cerință:
// Pentru un array de șiruri de caractere, returnează o listă de array-uri de șiruri, unde fiecare array din listă să conțină toate anagramele grupate.
// Dacă un șir de caractere nu are cel puțin o anagramă, ignoră-l.


#include <cstdio>
#include <vector>
#include <string>
#include <queue>

int hashFunction(const std::string& value)
{
    int hashResult = 0;
    for(auto &c : value)
    {
        hashResult += (int)c;
    }
    return hashResult;
}

class Compare {
public:
    bool operator()(std::pair<std::string, int> T1, std::pair<std::string, int> T2)
    {
        if(T1.second < T2.second)
            return true;
        return false;
    }

};

int main()
{
    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, Compare> sortedList;
    std::vector<std::pair<std::string, int>> inputList = {{"tca", 0}, {"go",0},{"act",0},{"flop",0},{"tac",0},{"cat",0},{"og",0},{"olfp",0}};
    for(auto &pair : inputList)
    {
        pair.second = hashFunction(pair.first);
        sortedList.push(pair);
    }

    int counter = 0;
    std::vector<std::vector<std::string>> finalList;
    for(int i = (int)sortedList.size() - 1; i >= 0 && !sortedList.empty(); i--)
    {
        auto firstElement = sortedList.top();
        sortedList.pop();
        bool hasFoundAtleastOneAnagram = false;
        std::vector<std::string> newElement;
        finalList.emplace_back(newElement).emplace_back(firstElement.first);
        while(true)
        {
            auto iterationElement = sortedList.top();
            if(firstElement.second == iterationElement.second)
            {
                hasFoundAtleastOneAnagram = true;
                if(!sortedList.empty())
                    finalList[counter].emplace_back(iterationElement.first);
            } else
            {
                counter++;
                break;
            }
            if(sortedList.empty())
            {
                break;
            }
            sortedList.pop();
        }
        if(!hasFoundAtleastOneAnagram)
        {
            finalList[counter].erase(finalList[counter].begin(), finalList[counter].begin()+1);
        }
    }
    for(auto &vector : finalList)
    {
        printf("[");
        for(auto &string : vector)
        {
            printf("%s, ", string.c_str());
        }
        printf("]\n");
    }
}
