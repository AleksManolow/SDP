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
    
    
    linkedList->reverse();
    linkedList->printList();

    delete linkedList;

    //Test operator==
    LinkedList<int> linkedListOne;
    linkedListOne.insertAtPos(6);
    linkedListOne.insertAtPos(81);
    linkedListOne.insertAtPos(78);
    LinkedList<int> linkedListTwo;
    linkedListTwo.insertAtPos(6);
    linkedListTwo.insertAtPos(81);
    linkedListTwo.insertAtPos(78);

    std::cout << linkedListOne.operator==(linkedListTwo) << std::endl;

    //Test Sort 
    LinkedList<int> linkedListSorted;
    linkedListSorted.insertAtPos(4);
    linkedListSorted.insertAtPos(5);
    linkedListSorted.insertAtPos(2);
    linkedListSorted.insertAtPos(7);
    linkedListSorted.insertAtPos(9);

    std::cout << "Before sort:"<< std::endl;
    linkedListSorted.printList();

    linkedListSorted.sort();
    std::cout << "After sort:"<< std::endl;
    linkedListSorted.printList();
    
    return 0;
}