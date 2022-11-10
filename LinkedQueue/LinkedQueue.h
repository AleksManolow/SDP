#ifndef __LINKEDQUEUE_H
#define __LINKEDQUEUE_H
#include <stdexcept>

template <typename T>
struct QueueElement {
    T data;
    QueueElement<T>* next;
    QueueElement(T const& _data, QueueElement<T>* _next = nullptr) :
        data(_data), next(_next) {} 
};

template <typename T>
class LinkedQueue
{
private:
    QueueElement<T> *front, *back;
    // инвариант на класа:
    // front == nullptr && back == nullptr || front != nullptr && back != nullptr

    void copy(LinkedQueue<T> const&);
    void erase();
public:
    LinkedQueue() : front(nullptr), back(nullptr) {}
    LinkedQueue(LinkedQueue<T> const&);
    LinkedQueue<T>& operator=(LinkedQueue<T> const&);
    ~LinkedQueue();

    // checks if a queue is empty
    bool empty() const { return front == nullptr; }

    // include an element at the end of the queue
    void enqueue(T const&);

    // removing the element at the head of the queue
    T dequeue();

    // looking at the element at the head of the queue
    T const& head() const;

    // looking at the item at the top of the queue with the ability to change
    T& head();
};

template<typename T>
void LinkedQueue<T>::enqueue(T const& element)
{
    QueueElement<T>* newElement = new QueueElement<T>(element);
    if (!front)
        front = newElement;
    else    
        back->next = newElement;
    back = newElement;
}

template<typename T>
T LinkedQueue<T>::dequeue()
{
    if (!front)
        throw std::runtime_error("Attempted to extract from empty queue");
    if (front == back)
        back == nullptr;
    
    QueueElement<T>* temp = front;
    front = front->next;
    T currDate = temp->data;
    delete temp;
    return currDate;
}

template<typename T>
T const& LinkedQueue<T>::head() const
{
    if (empty())
        throw std::runtime_error("Attempted to extract from empty queue");
    return front->data;
}

template<typename T>
T& LinkedQueue<T>::head()
{
    if (empty())
        throw std::runtime_error("Attempted to extract from empty queue");
    return front->data;
}

template<typename T>
LinkedQueue<T>::LinkedQueue(LinkedQueue<T> const& other)
{
    copy(other);
}

template<typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(LinkedQueue<T> const& other)
{
    if (this != &other)
    {
        erase();

        copy(other);
    }
    return *this;
}

template<typename T>
LinkedQueue<T>::~LinkedQueue()
{
    erase();
}

template<typename T>
void LinkedQueue<T>::copy(LinkedQueue<T> const& other)
{

    if (other.front != nullptr)
    {
        back = front = new QueueElement<T>(other.front->data, nullptr);
        QueueElement<T>* nextToCopy = other.front->next;
        while (nextToCopy)
        {
            back = back->next = new QueueElement<T>(nextToCopy->data, nullptr);
            nextToCopy = nextToCopy->next;
        }
    }
    else
        front = back = nullptr;
    
    
}

template<typename T>
void LinkedQueue<T>::erase()
{
    while (front)
    {
        QueueElement<T>* temp = front;
        front = front->next;
        delete temp;
    }
    front = back = nullptr;
}

#endif