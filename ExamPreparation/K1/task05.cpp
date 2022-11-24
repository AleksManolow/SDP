#include<iostream>
struct Node
{
    int data;
    Node* next;
};
Node* creatListWithMirrorElements(Node* list)
{
    Node* it = list;
    Node* newReveseNode = nullptr;

    while (it)
    {
        Node* crateNewNode = new Node();
        crateNewNode->data = it->data;
        crateNewNode->next = newReveseNode;
        newReveseNode = crateNewNode;
        it = it->next;
    }
    return newReveseNode;
}
void mirror(Node* list)
{   
        
    Node* mirrorList = creatListWithMirrorElements(list);

    Node* endEl = list;
    while (endEl->next)
    {
        endEl = endEl->next;
    }
    endEl->next = mirrorList;
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

    mirror(list1);

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