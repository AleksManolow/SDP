#include<iostream>
#include<stack>
template<typename T>
struct Node
{
    T data;
    Node<T>* next;

};
template<typename T>
int getNUmberOfElements(Node<T>* list)
{
    Node<T>* iter = list;
    int count = 0;
    while (iter)
    {
        count++;
        iter = iter->next;
    }
    return count;
}
template<typename T>
Node<T>* getMiddleElement(Node<T>* list)
{
    int numberEl = getNUmberOfElements(list);
    Node<T>* middleEl = list;
    for (size_t i = 0; i < numberEl / 2 - 1; i++)
    {
        middleEl = middleEl->next;
    }
    if (numberEl % 2 == 0)
        return middleEl;
    else    
        return middleEl->next;
    
}
template<typename T>
void shuffle(Node<T>* list)
{
    Node<T>* middleElIt = getMiddleElement(list);
    
    std::stack<Node<T>* > nodesToReverse;

    Node<T>* itToReverseEl = middleElIt->next;
    
    while (itToReverseEl)
    {
        nodesToReverse.push(itToReverseEl);
        itToReverseEl = itToReverseEl->next;
    }
    
    Node<T>* listToRevers = nodesToReverse.top();
    nodesToReverse.pop();

    while (!nodesToReverse.empty())
    {
        listToRevers->next = nodesToReverse.top();
        listToRevers = listToRevers->next;
        nodesToReverse.pop();
    }

    listToRevers->next = list;
    middleElIt->next = nullptr;
    
}
int main()
{

    Node<int>* six = new Node<int>;
	six->data = 6;
	six->next = nullptr;

    Node<int>* five = new Node<int>;
	five->data = 5;
	five->next = six;
  
	Node<int>* four = new Node<int>;
	four->data = 4;
	four->next = five;
  
	Node<int>* three = new Node<int>;
	three->data = 3;
	three->next = four;
  
	Node<int>* two = new Node<int>;
        two->data = 2;
	two->next = three;
  
	Node<int>* one = new Node<int>;
	one->next = two;
	one->data = 1;

    shuffle(one);

	while (six)
	{
		std::cout << six->data << " ";
		six = six->next;
	}

    return 0;
}