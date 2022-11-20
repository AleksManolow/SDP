#include<iostream>
#include"DoublyLinkedList.hpp"
int main()
{
    DoublyLinkedList<int> DLL;

    DLL.pushFront(465);
    DLL.pushFront(12);
    DLL.pushFront(15);
    DLL.pushFront(7);

    std::cout << DLL.front() << std::endl;
    DLL.popFront();
    std::cout << DLL.front() << std::endl;
    DLL.popFront();
    std::cout << DLL.front() << std::endl;
    DLL.popFront();
    std::cout << DLL.front() << std::endl;
    DLL.popFront();
    
    std::cout << DLL.empty() << std::endl;
}