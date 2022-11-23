#include<iostream>
struct Node
{
    int data;
    Node* next;
};
void rearange(Node*& list)
{
    Node* startEvenList = nullptr;
    Node* endEvenList = nullptr;

    Node* startOddList = nullptr;
    Node* endOddList = nullptr;

    while (list)
    {
        if (list->data % 2 == 0)
        {
            if (startEvenList == nullptr)
            {
                startEvenList = list;
                endEvenList = list;
            }
            else
            {
                endEvenList->next = list;
                endEvenList = endEvenList->next;
            }
        }
        else
        {
            if (startOddList == nullptr)
            {
                startOddList = list;
                endOddList = list;
            }
            else
            {
                endOddList->next = list;
                endOddList = endOddList->next;
            }
        }
        list = list->next;
    }
    list = startEvenList;
    endEvenList->next = startOddList;
    endOddList->next = nullptr;
}
int main()
{
    Node* list1 = new Node();
    list1->data = 1;
    list1->next = new Node();
    list1->next->data = 2;
    list1->next->next = new Node();
    list1->next->next->data = 4;
    list1->next->next->next = new Node();
    list1->next->next->next->data = 5;
    list1->next->next->next->next = nullptr;

    rearange(list1);

    Node* itForPrint = list1;
    while (itForPrint)
    {
        std::cout << itForPrint->data << std::endl;
        itForPrint = itForPrint->next;
    }
    
    while (list1)
    {
        Node* temp = list1;
        list1 = list1->next;
        delete temp;    
    }

    return 0;
}