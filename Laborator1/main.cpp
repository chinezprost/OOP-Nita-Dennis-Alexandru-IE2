// USED CLION IDE, PROBABLY DOESN'T WORK ON VISUAL STUDIO

#include <iostream>
#include <cstdio>
#include <list>
#include <stdlib.h>
#include <cstring>
using namespace std;


FILE *fp;
list<string> inputStrings;
list<string>::iterator i;
char inputString[100];

int convertToInt(string input)
{
    int number = 0, p = 1;
    for(int x = 1; x <= input.size(); x++)
    {
        //cout << input[input.size()-x] << " ";
        char myChar = input[input.size()-x];
        if(myChar >= '0' && myChar <= '9') {
            number = number + int(myChar - '0') * p;
            p *= 10;
        }
    }

    return number;
}

int main()
{
    if(fopen_s(&fp, "in.txt", "r") != 0) {
        printf("Couldn't open file.");
        return 0;
    }
    //printf("Opened file succesfully.");
    while (fgets(inputString, 100, fp) != nullptr) {
        inputStrings.emplace_back(inputString);
    }

    int sum = 0;
    for (i = inputStrings.begin(); i != inputStrings.end(); ++i) {
        auto n = convertToInt(*i);
        sum += n;
    }

    printf("%d\n", sum);

}