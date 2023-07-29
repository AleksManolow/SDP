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
bool hasCycle(Node* node)
{

    Node* slowIt = node;
    Node* fastIt = node;
    while (fastIt && fastIt->next && slowIt)
    {
        slowIt = slowIt->next;
        fastIt = fastIt->next->next;
        if (slowIt == fastIt)
        {
            return true;
        }
    }
    
    return false;
}
int main()
{
    Node* linkedList = new Node();
    linkedList->data = 5;
    linkedList->next = new Node();
    linkedList->next->data = 7;
    linkedList->next->next= new Node();
    linkedList->next->next->data = 10;
    linkedList->next->next->next = linkedList->next;

    std::cout << hasCycle(linkedList) << std::endl;

    //print(linkedList);

    //erase(linkedList);

    return 0;
}