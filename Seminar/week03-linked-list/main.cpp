#include<iostream>
#include"LinkedList.hpp"
int main()
{
    LinkedList<int>* linkedList = new LinkedList<int>();

    linkedList->insertAtPos(12);
    linkedList->insertAtPos(2);
    linkedList->insertAtPos(6);
    linkedList->insertAtPos(81);
    linkedList->insertAtPos(78);

    linkedList->removeAtPos(2);
    int elementAtPosition = linkedList->getElementAtPos(2);
    std::cout << elementAtPosition << std::endl;
    int topEl = linkedList->top();
    std::cout << topEl << std::endl;
    linkedList->printList();


    delete linkedList;
    return 0;
}