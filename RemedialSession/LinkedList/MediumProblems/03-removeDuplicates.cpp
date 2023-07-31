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
void removeDuplicate(Node* node)
{
    Node* firstIt = node;
    Node* secoundIt = nullptr;
    while (firstIt != nullptr && firstIt->next != nullptr)
    {
        secoundIt = firstIt;
        while (secoundIt->next != nullptr)
        {
            if (secoundIt->next->data == firstIt->data)
            {
                Node* dup = secoundIt->next;
                secoundIt->next = secoundIt->next->next;
                delete dup;
            }
            else
            {
                secoundIt = secoundIt->next;
            }
            
        }
        firstIt = firstIt->next;
    }
}
int main()
{
    Node* linkedList = new Node();
    linkedList->data = 12;
    linkedList->next = new Node();
    linkedList->next->data = 7;
    linkedList->next->next= new Node();
    linkedList->next->next->data = 12;
    linkedList->next->next->next = nullptr;

    print(linkedList);

    removeDuplicate(linkedList);

    print(linkedList);

    erase(linkedList);

    return 0;
}