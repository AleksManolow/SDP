#include<iostream>
#include"LinkedQueue.h"
int main()
{
    LinkedQueue<int>* queue = new LinkedQueue<int>();
    queue->enqueue(5);
    queue->enqueue(9);
    queue->enqueue(7);
    queue->enqueue(45);

    std::cout << queue->dequeue() << std::endl;
    std::cout << queue->dequeue() << std::endl;
    std::cout << queue->dequeue() << std::endl;
    std::cout << queue->dequeue() << std::endl;

    return 0;
}