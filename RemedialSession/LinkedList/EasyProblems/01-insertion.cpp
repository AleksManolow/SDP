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
//Function Insert a Node On Given Position in Linked List
void insertOnPosition(Node*& node, int new_data, int pos)
{
    if (pos == 0)
    {
        Node* newNode = new Node();
        newNode->data = new_data;
        newNode->next = node;
        node = newNode;
    }
    else
    {
        Node* tempNode = node;
        while (pos != 1 && node->next != nullptr)
        {
            node = node->next;
            pos--;
        }

        Node* newNode = new Node();
        newNode->data = new_data;

        if (node->next == nullptr)
            newNode->next = nullptr;
        else
            newNode->next = node->next;

        node->next = newNode;
        node = tempNode;
    }
}
int main()
{
    Node* linkedList = new Node();
    linkedList->data = 5;
    linkedList->next = new Node();
    linkedList->next->data = 15;
    linkedList->next->next = nullptr;

    insertOnPosition(linkedList, 8, 1);

    print(linkedList);

    erase(linkedList);

    return 0;
}