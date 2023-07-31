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
void segregateEvenAndOdd(Node* node)
{
    Node* startEven = nullptr;
    Node* startOdd = nullptr ;

    Node* evenIt;
    Node* oddIt;

    while (node)
    {
        if (node->data % 2 == 0)
        {
            if (startEven == nullptr)
            {
                startEven = node;
                evenIt = node;
            }
            else
            {
                evenIt->next = node;
                evenIt = evenIt->next;
            }
            
        }
        else
        {
            if (startOdd == nullptr)
            {
                startOdd = node;
                oddIt = node;
            }
            else
            {
                oddIt->next = node;
                oddIt = oddIt->next;
            }
        }    
        node = node->next;
    }
    evenIt->next = nullptr;
    oddIt->next = nullptr;

    print(startEven);
    print(startOdd);
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

    segregateEvenAndOdd(list1);

    erase(list1);

    return 0;
}