#include<iostream>
struct Node
{
    int data;
    Node* next;
};
void removeConsecutiveDuplicates(Node* list)
{
    Node* it = list;
    while (it->next)
    {
        if (it->data == it->next->data)
        {
            Node* deleteNode = it->next;
            it->next = deleteNode->next;
            delete deleteNode;
        }
        it = it->next;
    }
}
int main()
{
    Node* list1 = new Node();
    list1->data = 1;
    list1->next = new Node();
    list1->next->data = 2;
    list1->next->next = new Node();
    list1->next->next->data = 2;
    list1->next->next->next = new Node();
    list1->next->next->next->data = 4;
    list1->next->next->next->next = new Node();
    list1->next->next->next->next->data = 4;
    list1->next->next->next->next->next = new Node();
    list1->next->next->next->next->next->data = 6;
    list1->next->next->next->next->next->next = nullptr;

    removeConsecutiveDuplicates(list1);

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