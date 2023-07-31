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
Node* reverse(Node* list)
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
    return list;
}
Node* intersectionOfTwoSorted(Node* a, Node* b)
{
    Node* node = nullptr;

    while (a != nullptr && b != nullptr)
    {
        if(a->data == b->data)
        {
            Node* newNode = new Node();
            newNode->data = a->data;
            newNode->next = node;
            node = newNode;
            a = a->next;
            b = b->next;
        }
        else if(a->data < b->data)
            a = a->next;
        else
            b = b->next;
    }
    return reverse(node);
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
    b->data = 2;
    b->next = new Node();
    b->next->data = 4;
    b->next->next= new Node();
    b->next->next->data = 5;
    b->next->next->next = nullptr;

    Node* newNode = intersectionOfTwoSorted(a, b);

    print(newNode);

    erase(a);
    erase(b);
    erase(newNode);

    return 0;
}