#include<iostream>
struct Node
{
    int data;
    Node* next;
};
void oddEvenList(Node*& list)
{
    Node* startOddList = nullptr;
    Node* endOddList = nullptr;

    Node* startEvenList = nullptr;
    Node* endEvenList = nullptr;

    int count = 1;
    while (list)
    {
        if (count % 2 == 0)
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
        count++;
        list = list->next;
    }
    list = startOddList;
    endOddList->next = startEvenList;
    endEvenList->next = nullptr;
}
int main()
{
    
    Node* list1 = new Node();
    list1->data = 1;
    list1->next = new Node();
    list1->next->data = 2;
    list1->next->next = new Node();
    list1->next->next->data = 3;
    list1->next->next->next = new Node();
    list1->next->next->next->data = 4;
    list1->next->next->next->next = nullptr;

    oddEvenList(list1);

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