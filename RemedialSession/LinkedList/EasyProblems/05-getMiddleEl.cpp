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
int getLen(Node* node)
{
    int count = 0;
    while (node != nullptr)
    {
        node = node->next;
        count++;
    }
    return count;
}
int getMiddleEl(Node* node)
{
    int midIdx = getLen(node) / 2;
    while (midIdx != 0)
    {
        node = node->next;
        midIdx--;
    }
    return node->data;
}
int main()
{
    Node* linkedList = new Node();
    linkedList->data = 5;
    linkedList->next = new Node();
    linkedList->next->data = 7;
    linkedList->next->next= new Node();
    linkedList->next->next->data = 10;
    linkedList->next->next->next = nullptr;

    std:: cout << getMiddleEl(linkedList) << std::endl;

    print(linkedList);

    erase(linkedList);

    return 0;
}