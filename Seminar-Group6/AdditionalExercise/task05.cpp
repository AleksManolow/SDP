#include<iostream>
#include<stack>

template<typename T>
struct Node
{
    T data;
    Node* next;
};
template<typename T>
void equalize(Node<T>* ll)
{
    std::stack<int> temp;
    Node<T>* iter = ll;

    while(iter) {
        while(!iter->data.empty()) {
            temp.push(iter->data.top());
            iter->data.pop();
        }
        iter = iter->next;
    }

    iter = ll;

    while(!temp.empty()) {
        if(iter == nullptr) {
            iter = ll;
        }
        iter->data.push(temp.top());
        temp.pop();
        iter = iter->next;
    }
}
int main()
{
    Node<std::stack<int>>* list1 = new Node<std::stack<int>>();
    list1->data = std::stack<int>({1, 4});
    list1->next = new Node<std::stack<int>>();
    list1->next->data = std::stack<int>({6, 7, 8, 9, 5});
    list1->next->next = new Node<std::stack<int>>();
    list1->next->next->data = std::stack<int>({10, 11, 12});
    list1->next->next->next = new Node<std::stack<int>>();
    list1->next->next->next->data = std::stack<int>({1, 41});
    list1->next->next->next->next = new Node<std::stack<int>>();
    list1->next->next->next->next->data = std::stack<int>({6, 7, 8, 9, 5, 7, 9, 0, 10, 20, 30});
    list1->next->next->next->next->next = nullptr;

    equalize(list1);

    Node<std::stack<int>>* itForPrint = list1;
    while (itForPrint)
    {
        std::stack<int> a = itForPrint->data;
        while (!a.empty())
        {
            std::cout << a.top() << " ";
            a.pop();
        } 
        std::cout << std::endl;
        itForPrint = itForPrint->next;
    }
    
    while (list1)
    {
        Node<std::stack<int>>* temp = list1;
        list1 = list1->next;
        delete temp;    
    }

    return 0;
}