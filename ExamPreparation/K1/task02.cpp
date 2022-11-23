#include<iostream>
struct Node
{
    int data;
    Node* prev;
    Node* next;
    
    Node(int data, Node* prev, Node* next)
    :data(data), prev(prev), next(next){}
};
void mirror(Node* first)
{
    Node* endIt = first;
    while (endIt->next)
    {
        endIt = endIt->next;
    }

    Node* it = endIt;
    while (endIt)
    {
        Node* newNode = new Node(endIt->data, it, nullptr);
        it->next = newNode;
        it = it->next;
        endIt = endIt->prev;
    }
}
int main()
{
    Node* fst = new Node(1 ,nullptr, nullptr);
    Node* sec = new Node(4, fst, nullptr);
    fst->next = sec;
    Node* third = new Node(6, sec, nullptr);
    sec->next = third;
    Node* fourth = new Node(8, third, nullptr);
    third->next = fourth;

    mirror(fst);

    Node* result = fst;
    while (result)
	{
		std::cout << result->data << " ";
		result = result->next;
	}

    while (fst)
    {
        Node* temp = fst;
        fst = fst->next;
        delete temp;
    }
    

    return 0;
}