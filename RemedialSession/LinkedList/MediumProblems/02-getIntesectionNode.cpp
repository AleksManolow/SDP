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
}Node* getIntesectionNode(Node* head1, Node* head2)
{
    while (head1 != nullptr)
    {
        Node* tempItHead2 = head2;
        while (tempItHead2 != nullptr)
        {
            if (tempItHead2 == head1)
                return tempItHead2;
            tempItHead2 = tempItHead2->next;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return nullptr;
}
int main()
{
    Node* linkedList = new Node();
    linkedList->data = 5;
    linkedList->next = new Node();
    linkedList->next->data = 7;
    linkedList->next->next= new Node();
    linkedList->next->next->data = 12;
    linkedList->next->next->next = nullptr;

    Node* linkedList2 = new Node();
    linkedList2->data = 10;
    linkedList2->next = new Node();
    linkedList2->next->data = 78;
    linkedList2->next->next = linkedList->next->next;

    std::cout << getIntesectionNode(linkedList, linkedList2)->data << std::endl;
    

    //print(linkedList);

    erase(linkedList);

    return 0;
}