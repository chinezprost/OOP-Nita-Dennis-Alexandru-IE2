#include <iostream>
#include "NumberList.h"
int a = 1, b = 2, c = 3, d = 5;
NumberList numberList;
int main()
{
    numberList.Init();

    numberList.Add(d);
    numberList.Add(b);
    numberList.Add(9);
    numberList.Add(a);

    numberList.Print();
    //should show 5 2 9 1
    numberList.Sort();

    numberList.Print();
    //should show 1 2 5 9
}