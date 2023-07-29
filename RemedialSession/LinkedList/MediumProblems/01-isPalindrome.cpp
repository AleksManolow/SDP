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
bool isPalindrome(Node* node)
{
    Node* reverseNode = reverse(node);
    while (node != nullptr && reverseNode != nullptr)
    {
        if (node->data != reverseNode->data)
        {
            return false;
        }
        node = node->next;
        reverseNode = reverseNode->next;
    }
    return true;
}
int main()
{
    Node* linkedList = new Node();
    linkedList->data = 5;
    linkedList->next = new Node();
    linkedList->next->data = 7;
    linkedList->next->next= new Node();
    linkedList->next->next->data = 5;
    linkedList->next->next->next = nullptr;

    std::cout << isPalindrome(linkedList) << std::endl;

    //print(linkedList);

    erase(linkedList);

    return 0;
}