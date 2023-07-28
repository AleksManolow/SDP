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
void sortedInsert(Node*& node, int newData)
{
    Node* tempNode = node;

    if (tempNode->data > newData)
    {
        Node* newNode = new Node();
        newNode->data = newData;
        newNode->next = tempNode;
        node = newNode;
    }
    else{
        while (tempNode->next != nullptr)
        {
            if (tempNode->data < newData && tempNode->next->data > newData)
            {
                Node* newNode = new Node();
                newNode->data = newData;
                newNode->next = tempNode->next;
                tempNode->next = newNode;
                break;
            }
            tempNode = tempNode->next;
        }

        if (tempNode->next == nullptr)
        {
            Node* newNode = new Node();
            newNode->data = newData;
            newNode->next = nullptr;
            tempNode->next = newNode;
        }
    }
    

    
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

    sortedInsert(linkedList, 4);

    print(linkedList);

    erase(linkedList);

    return 0;
}