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
void deleteNodes(Node*& node)
{
    Node* it = node;
    Node* prev = node;

    while (it->next)
    {
        if (it == node)
        {
            if (it->data < it->next->data)
            {
                Node* deleteNode = it;
                it = it->next;
                delete deleteNode; 
                node = it;
                prev = it;
            }
            else
            {
                it = it->next;
            }
        }
        else
        {
            if (it->data < it->next->data)
            {
                Node* deleteNode = it;
                it = it->next;
                prev->next = it;
                delete deleteNode; 
            }
            else
            {
                it = it->next;
                prev = prev->next;
            }
        }
    }
}
int main()
{
    Node* list1 = new Node();
    list1->data = 12;
    list1->next = new Node();
    list1->next->data = 15;
    list1->next->next = new Node();
    list1->next->next->data = 10;
    list1->next->next->next = new Node();
    list1->next->next->next->data = 11;
    list1->next->next->next->next = new Node();
    list1->next->next->next->next->data = 5;
    list1->next->next->next->next->next = nullptr;

    deleteNodes(list1);

    print(list1);

    erase(list1);

    return 0;
}