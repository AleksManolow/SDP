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
//Function Insert a Node at the Front/Beginning of Linked List
void pushNode(Node*& ll, int value)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = ll;
    ll = newNode;
}
int main()
{
    Node* linkedList = new Node();
    linkedList->data = 5;
    linkedList->next = new Node();
    linkedList->next->data = 15;
    linkedList->next->next = nullptr;

    pushNode(linkedList, 16);

    print(linkedList);

    erase(linkedList);

    return 0;
}