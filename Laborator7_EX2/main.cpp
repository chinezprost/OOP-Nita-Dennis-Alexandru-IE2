#include <cstdio>
#include "Tree.h"
#include "Node.h"

Tree<int> myTree;

bool less(int value1, int value2)
{
    return value1 < value2;
}

bool greater(int value1, int value2)
{
    return value1 > value2;
}

int main(void)
{
    /*
    1 -> 2 -> 4
      -> 3 -> 5 -> 7
           -> 6
           -> 8
    */
    Node<int> *node1 = &myTree.add_node(nullptr, new Node<int>(1));
    Node<int> *node2 = &myTree.add_node(node1, new Node<int>(2));
    Node<int> *node3 = &myTree.add_node(node1, new Node<int>(3));
    Node<int> *node4 = &myTree.add_node(node2, new Node<int>(4));
    Node<int> *node5 = &myTree.add_node(node3, new Node<int>(5));
    Node<int> *node6 = &myTree.add_node(node3, new Node<int>(6));
    Node<int> *node7 = &myTree.add_node(node5, new Node<int>(7));
    Node<int> *node8 = &myTree.add_node(node3, new Node<int>(8));

    printf("The second child of node 3 is: %d\n", myTree.get_node(node3, 1).info);
    printf("The third child of node 3 is: %d\n", myTree.get_node(node3, 2).info);

    auto searchedNode = myTree.find(myTree.get_root(), 11);
    if(searchedNode == nullptr)
        printf("Node %d not found.\n", 11);
    else
        printf("Found node: %d\n", searchedNode->info);

    searchedNode = myTree.find(myTree.get_root(), 7);
    if(searchedNode == nullptr)
        printf("Node %d not found.\n", 7);
    else
        printf("Found node: %d\n", searchedNode->info);

    myTree.delete_node(node7);
    printf("Deleted node 7.\n");

    searchedNode = myTree.find(myTree.get_root(), 7);
    if(searchedNode == nullptr)
        printf("Node %d not found.\n", 7);
    else
        printf("Found node: %d\n", searchedNode->info);

    Node<int> *node9 = &myTree.insert(node5, new Node<int>(9), 3);
    printf("Inserted node 9 as child of node 5 at position 3.\n");

    myTree.sort(node3, greater);
    printf("Children of node 3 have been sorted: ");
    for(int i = 0; i < node3->getChildrenCount(); i++)
        printf("%d ", node3->children[i]->info);
    printf("\n");
    printf("Node 3 has %d children.\n", 3);






}