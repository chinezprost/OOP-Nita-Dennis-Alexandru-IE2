#pragma once

#include <algorithm>
#include "Node.h"

template <typename T>
class Tree
{
private:
    Node<T> **rootNode = new Node<T>*[10];
    int rootNodeChildrenCount = 0;

public:



    Node<T>** get_root()
    {
        if (this->rootNode == nullptr)
        {
            printf("Tree is empty. Can not find any root.\n");
            return nullptr;
        }

        return this->rootNode;
    }

    Node<int>& add_node(Node<T>* parentNode, Node<T>* node)
    {
        if (parentNode == nullptr)
        {
            printf("Tree is empty. Adding node %d as root.\n", node->info);
            this->rootNode[rootNodeChildrenCount++] = node;
            return *node;
        }


        parentNode->children[parentNode->childCount++] = node;
        return *node;
    }

    Node<T>& get_node(Node<T>* parentNode, int index)
    {
        return *parentNode->children[index];
    }

    void delete_node(Node<T>* node)
    {
        if (node == nullptr)
            return;

        for (int i = 0; i < node->getChildrenCount(); i++)
            delete_node(node->children[i]);

        delete[] node;
        node = nullptr;
    }
    Node<T>* found_node = nullptr;
    Node<T>* recursive_find(Node<T>* nextNode, T value)
    {
        if(nextNode->info == value && found_node == nullptr)
        {
            found_node = nextNode;
            return nextNode;
        }

        for(int i = 0; i < nextNode->childCount; i++)
                recursive_find(nextNode->children[i], value);
    }

    Node<T>* find(Node<T>** nextNode, T value)
    {
        found_node = nullptr;
        for(int i = 0; i < this->rootNodeChildrenCount; i++)
            recursive_find(nextNode[i], value);
        return found_node;
    }



    Node<T>& insert(Node<T>* parentNode, Node<T>* node, int index)
    {
        if (parentNode == nullptr)
        {
            printf("Tree is empty. Adding node %d as root.\n", node->info);
            this->rootNode[rootNodeChildrenCount++] = node;
            return *node;
        }


        parentNode->children[index] = node;
        return *node;
    }

    bool sort(Node<T>* node, bool (*callback)(int, int))
    {
        if(callback == nullptr)
        {
            for(int i = 0; i < node->getChildrenCount()-1; i++)
                for(int j = i + 1; j < node->getChildrenCount(); j++)
                {
                    if(callback(node->children[i]->info, node->children[j]->info))
                        std::swap(node->children[i], node->children[j]);
                }
        }
    }

    int count(Node<T>* node, int nodeCount = 0)
    {

    }


};