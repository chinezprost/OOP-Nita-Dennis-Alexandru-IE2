#include "Sort.h"
#include <iostream>

int main()
{
    /*  Sort(int _numberCount, int _min, int _max);
        Sort(std::list<int> _inputContainer);
        Sort(int* _inputVector, int _inputVectorElementCount);
        Sort(int _count, ...);
        Sort(char* _inputString);*/

    int vector[10] = { 5,7,52,12,15,2 };
    int vectorLength = 6;
    Sort minMaxList(5, 0, 10);
    Sort initListList{ { 1,2,3,4,5 } };
    Sort inputVectorList(vector, vectorLength);
    Sort variadicList(6, 4, 2, 1, 7, 5, 4);
    Sort inputStringList("900,40,100,5,7");

    std::cout << "QuickSort: Variadic list: (up)\n";
    variadicList.QuickSort(0, variadicList.GetElementsCount()-1, true);
    variadicList.Print();
    std::cout << '\n';

    std::cout << "BubbleSort: Init. List: (up)\n";
    initListList.BubbleSort(true);
    initListList.Print();
    std::cout << '\n';

    std::cout << "QuickSort: Input Vector List: (up) \n";
    inputVectorList.QuickSort(0, inputVectorList.GetElementsCount() - 1, true);
    inputVectorList.Print();
    std::cout << '\n';

    std::cout << "InsertSort: Randomized List: (down) \n";
    minMaxList.InsertSort();
    minMaxList.Print();
    std::cout << '\n';

    std::cout << "BubbleSort: Input String: (down)\n";
    inputStringList.BubbleSort();
    inputStringList.Print();
   

}