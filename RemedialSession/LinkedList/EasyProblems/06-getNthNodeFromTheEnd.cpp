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
int getNthFromLast(Node* node, int N)
{
    int len = getLen(node);

    int count = len - N + 1;

    while (count != 1)
    {
        node = node->next;
        count--;
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

    std:: cout << getNthFromLast(linkedList, 3) << std::endl;

    print(linkedList);

    erase(linkedList);

    return 0;
}