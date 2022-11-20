#include<iostream>
#include"DoublyLinkedList.hpp"
int main()
{
    DoublyLinkedList<int> DLL;

    DLL.pushFront(465);
    DLL.pushFront(12);
    DLL.pushFront(15);
    DLL.pushFront(7);

   
   for (auto it : DLL)
    {
        std::cout << it << std::endl;
    }

    for (auto it = DLL.begin(); it != DLL.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    
    return 0;
}