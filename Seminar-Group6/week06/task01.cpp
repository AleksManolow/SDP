#include<iostream>
#include<list>
#include"../week04/linked-list-utils.h"
#include<algorithm>
#include<ctime>
template<class T>
void insertSorted(LinkedListNode<T>*& ll, const T& elem)
{   
    LinkedListNode<T>* toInsert = new LinkedListNode<T>(elem);

    if (ll = nullptr)
    {
        ll = toInsert;
    }
    else if(toInsert->data < ll->data)
    {
        toInsert->next = ll;
        ll = toInsert;
    }
    else if (ll->next == nullptr)
    {
        ll->next = toInsert;
    }
    else
    {
        LinkedListNode<T>* it = ll;
        while (it->next == nullptr)
        {
            if (it->next->data > elem)
            {
                LinkedListNode<T>* nNext = it->next;
                it->next = toInsert;
                toInsert->next = nNext;
                break;
            }
            it = it->next;
        }
        it->next = toInsert;	
    }
}
template<class T>
void insertSorted(std::list<T>& ll, const T& elem)
{
    auto iter = ll.begin();

    while (iter != ll.end())
    {
        if (*iter > elem )
        {
            ll.insert(iter, elem);
        }
        ++iter;
    }

    if (iter == ll.end())
    {
        ll.push_back(elem);
    }
}
int main()
{
    std::list<int> ll;

    srand(time(NULL));

    for (size_t i = 0; i < 55555; i++)
        insertSorted(ll, rand());

    std::cout << std::is_sorted(ll.begin(), ll.end());
    return 0 ;
}