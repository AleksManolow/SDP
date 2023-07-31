#include<iostream>
class Node{
    public:
    int data;
    Node *next;
};
void erase(Node* ll) {
    while(ll != nullptr) {
        Node* toDelete = ll;
        ll = ll->next;
        delete toDelete;
    }
}
void print(Node* ll)
{
    while (ll != nullptr)
    {
        std::cout << ll->data << " ";
        ll = ll->next;
    }
    std::cout << std::endl;
}
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
    Node* a = new Node();
    a->data = 1;
    a->next = new Node();
    a->next->data = 2;
    a->next->next= new Node();
    a->next->next->data = 4;
    a->next->next->next = nullptr;

    Node* b = new Node();
    b->data = 3;
    b->next = new Node();
    b->next->data = 5;
    b->next->next= new Node();
    b->next->next->data = 8;
    b->next->next->next = nullptr;

    Node* newNode = mergeTwoLists(a, b);

    print(newNode);

    erase(newNode);

    return 0;
}