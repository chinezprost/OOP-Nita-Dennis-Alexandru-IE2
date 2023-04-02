#pragma once
#include <stdlib.h>
#include <stdio.h>
template <class T>
class Node
{
private:

public:
    T info;
    Node<T>* children[10];
    int childCount = 0;
    Node()
    {

    }

    Node<T>* operator [](int i)
    {
        if (i >= childCount)
            return nullptr;
        return this->children[i];
    }

    Node(T value)
    {
        this->info = value;
        //this->children = (Node*)malloc(sizeof(Node<T>) + 1);
    }


    void deleteChildren()
    {
        delete[] this->children;
    }

    int getChildrenCount()
    {
        return this->childCount;
    }



    T getValue()
    {
        return this->info;
    }

};