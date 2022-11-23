#include<iostream>
struct Node
{
    int data;
    Node* next;
};
int sizeList(Node* list)
{
    int count = 0;
    while (list)
    {
        count++;
        list = list->next;
    }
    return count;
}
void inc(Node* list)
{
    int median = sizeList(list) / 2;

    Node* it = list;
    int count = 0;
    while (it)
    {
        if (count < median)
        {
            if (it->data == 0)
                it->data = 9;
            else 
                it->data = it->data - 1;
        }
        else
        {
            if (it->data == 9)
                it->data = 0;
            else 
                it->data = it->data + 1;
        }
        count++;
        it = it->next;
    }   
}
int main()
{
    Node* list1 = new Node();
    list1->data = 0;
    list1->next = new Node();
    list1->next->data = 2;
    list1->next->next = new Node();
    list1->next->next->data = 2;
    list1->next->next->next = new Node();
    list1->next->next->next->data = 4;
    list1->next->next->next->next = new Node();
    list1->next->next->next->next->data = 4;
    list1->next->next->next->next->next = new Node();
    list1->next->next->next->next->next->data = 9;
    list1->next->next->next->next->next->next = nullptr;

    inc(list1);

    Node* itForPrint = list1;
    while (itForPrint)
    {
        std::cout << itForPrint->data << " ";
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