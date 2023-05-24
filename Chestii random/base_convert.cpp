#include <cstdio>
#include <string>

int charToInt(const char& value)
{
    if(value >= '0' && value <= '9')
    {
        return value - '0';
    }
    else
    {
        return value + 10 - 'A';
    }
}

char intToChar(const int& value)
{
    if(value >= 0 && value <= 9)
    {
        return value + '0';
    }
    else
    {
        return value - 10 + 'A';
    }
}

std::string fromBase10(int value, const int& base)
{
    std::string result;
    while(value > 0)
    {
        result.insert(0,1, intToChar(value % base));
        value /= base;
    }
    return result;
}

int toBase10(const std::string& value, const int& base)
{
    int result = 0;
    int power = 1;
    for(int i = value.size() - 1; i >= 0; i--)
    {
        result += charToInt(value[i]) * power;
        power *= base;
    }
    return result;
}


int main()
{
    std::string inputNumber1 = "11A";
    int inputNumber2 = 282;
    printf("%s\n",fromBase10(inputNumber2, 16).c_str());
    printf("%d\n",toBase10(inputNumber1, 16));
}