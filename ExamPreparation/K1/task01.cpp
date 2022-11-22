#include<iostream>
struct Node
{
    int data;
    Node* next;
};
void fillgaps(Node* list)
{
    if (!list)
    {
        return;
    }
    

    while (list->next)
    {
        if (list->next->data - list->data > 1)
        {
            Node* newNode = new Node;
            newNode->data = list->data + 1;
            newNode->next = list->next;
            list->next = newNode;
        }
        list = list->next;
    }
    
}
int main()
{
    Node* two = new Node;
    two->data = 6;
	two->next = nullptr;
  
	Node* one = new Node;
	one->next = two;
	one->data = 2;

    fillgaps(one);

	while (one)
	{
		std::cout << one->data << " ";
		one = one->next;
	}

    return 0;
}