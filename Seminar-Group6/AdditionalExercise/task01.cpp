#include<iostream>
struct Node
{
    int data;
    Node* next;
};
Node* mergeTwoLists(Node* list1, Node* list2)
{
    if (!list1)
    {
        return list2;
    }
    if (!list2)
    {
        return list1;
    }
     
    Node* start = nullptr;
    Node* it = nullptr;

    while (list1 && list2)
    {
        if (list1->data < list2->data)
        {
            if (it == nullptr)
            {
                start = list1;
                it = list1;
            }
            else   
            {
                it->next = list1;
                it = it->next;
            }
            list1 = list1->next;
        }
        else
        {
            if (it == nullptr)
            {
                start = list2;
                it = list2;
            }
            else   
            {
                it->next = list2;
                it = it->next;
            }
            list2 = list2->next;
        }
    }
    if (list1 != nullptr)
    {
        it->next = list1;
    }
    else if (list2 != nullptr)
    {
        it->next = list2;
    }
    else
    {     
        it->next = nullptr;
    }
    
    return start;
}
int main()
{     
    Node* list1 = new Node();
    list1->data = 1;
    list1->next = new Node();
    list1->next->data = 3;
    list1->next->next = new Node();
    list1->next->next->data = 4;
    list1->next->next->next = nullptr;

    Node* list2 = new Node();
    list2->data = 2;
    list2->next = new Node();
    list2->next->data = 5;
    list2->next->next = new Node();
    list2->next->next->data = 6;
    list2->next->next->next = nullptr;

    Node* result = mergeTwoLists(list1, list2);

    Node* itForPrint = result;
    while (itForPrint)
    {
        std::cout << itForPrint->data << std::endl;
        itForPrint = itForPrint->next;
    }
    
    
    while (result)
    {
        Node* temp = result;
        result = result->next;
        delete temp;    
    }
    return 0;
}