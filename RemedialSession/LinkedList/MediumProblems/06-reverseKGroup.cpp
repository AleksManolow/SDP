#include<iostream>
struct Node
{
    int data;
    Node* next;
};
Node* getNext(Node* list, int k)
{
    while(k && list) {
        list = list->next;
        --k;
    }

    return list;
}
void reverse(Node*& list)
{   
    Node* next = nullptr;
    Node* prev = nullptr;
    Node* it = list;

    while (it)
    {
        next = it->next;
        it->next = prev;
        prev = it;
        it = next;
    }
    list = prev;
}
Node* reverseKGroup(Node* list, int k)
{   
    Node* end = getNext(list, k - 1);

    if (end == nullptr)
    {
        return list;
    }
    Node* next = end->next;

    end->next = nullptr;

    Node* last = list;
    reverse(list);
    Node* res = reverseKGroup(next, k);

    last->next = res;
    return list;
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
    list1->next->next->next->next = new Node();
    list1->next->next->next->next->data = 5;
    list1->next->next->next->next->next = nullptr;

    Node* result = reverseKGroup(list1, 2);

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