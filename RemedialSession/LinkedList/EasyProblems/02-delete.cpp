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
void deleteOnPosition(Node*& node, int pos)
{
    if (pos == 0)
    {
        Node* deleteNode = node;
        node = node->next;
        delete deleteNode;
    }
    else
    {
        Node* tempNode = node;
        while (pos != 1 && node->next != nullptr)
        {
            node = node->next;
            pos--;
        }

        Node* deletedNode = node->next;

        node->next = node->next->next;
        node = tempNode;
    }
}
int main()
{
    Node* linkedList = new Node();
    linkedList->data = 5;
    linkedList->next = new Node();
    linkedList->next->data = 15;
    linkedList->next->next= new Node();
    linkedList->next->next->data = 10;
    linkedList->next->next->next = nullptr;

    deleteOnPosition(linkedList, 0);
    
    print(linkedList);

    erase(linkedList);

    return 0;
}