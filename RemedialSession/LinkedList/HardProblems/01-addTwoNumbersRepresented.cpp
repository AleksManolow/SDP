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
int convertLinkedListToNumber(Node* node)
{
    int number = 0;
    while (node)
    {
        number *= 10;
        number += node->data;
        node = node->next;
    }
    return number;
}
Node* sumLinkedLists(Node* a, Node* b)
{
    int numberA = convertLinkedListToNumber(a);
    int numberB = convertLinkedListToNumber(b);
    int resultNumber = numberA + numberB;

    Node* result = nullptr;
    while (resultNumber)
    {
        Node* newNode = new Node();
        newNode->data = resultNumber % 10;
        newNode->next = result;
        result = newNode;
        resultNumber /= 10;
    }
    return result;
}
int main()
{
    Node* list1 = new Node();
    list1->data = 5;
    list1->next = new Node();
    list1->next->data = 6;
    list1->next->next = new Node();
    list1->next->next->data = 3;
    list1->next->next->next = nullptr;

    Node* list2 = new Node();
    list2->data = 8;
    list2->next = new Node();
    list2->next->data = 4;
    list2->next->next = new Node();
    list2->next->next->data = 2;
    list2->next->next->next = nullptr;


    Node* result = sumLinkedLists(list1, list2);

    print(result);

    erase(list1);
    erase(list2);

    erase(result);

    return 0;
}