#ifndef DOUBLY_LINKED_LIST_IMPL_
#define DOUBLY_LINKED_LIST_IMPL_

#include<exception>

template<typename T>
struct DLListNode {
    T data;
    DLListNode<T>* prev;
    DLListNode<T>* next;

    DLListNode(const T& elem, DLListNode<T>* n = nullptr, DLListNode<T>* p = nullptr) : data{elem}, next {n}, prev{p} {} 
};


template<typename T>
class DoublyLinkedList 
{
private:
    using Node = DLListNode<T>;

    Node* head;
    Node* tail;

    void copy(const DoublyLinkedList<T>& other)
    {
        Node* otherIter = other.head;
	    while (otherIter != nullptr)
	    {
		    pushBack(otherIter->data);
		    otherIter = otherIter->next;
	    }
    }
    void free()
    {
        while (!empty())
            popBack();
    }
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    DoublyLinkedList(const DoublyLinkedList<T>& other)
    {
        copy(other);
    }
    DoublyLinkedList& operator=(const DoublyLinkedList<T>& other)
    {
        if (this != &other)
        {
            free();
            copy(other);
        }
        
        return *this;
    }

    DoublyLinkedList(DoublyLinkedList<T>&& DLL);
    DoublyLinkedList& operator=(DoublyLinkedList<T>&& DLL);

    void pushBack(const T& value)
    {
        Node* newElement = new Node(value);
        if (empty())
            head = newElement;
        else
            newElement->prev = tail;
        tail = newElement;
    }
    void popBack()
    {
        if (empty())
		    throw std::runtime_error("The list is empty!");

        Node* deletedElem = tail;

        if (head == tail)
            head = nullptr;
        else
            tail->prev->next = nullptr;

        tail = tail->prev;
        delete deletedElem; 
    }

    void pushFront(const T& value)
    {
        Node* newElement = new Node(value);
        if (empty())
            tail = newElement;
        else
            newElement->next = head;
        head = newElement;
    }
    void popFront()
    {
        if (empty())
		    throw std::runtime_error("The list is empty!");

        Node* deletedElem = head;

        if (head == tail)
            tail = nullptr;
        else
            head->next->prev = nullptr;

        head = head->next;
        delete deletedElem; 
    }

    bool empty() const
    {
        return head == nullptr && tail == nullptr;
    }

    const T& back() const
    {
        if (empty())
		    throw std::runtime_error("The list is empty!");
        return tail->data;
    }
    const T& front() const
    {
        if (empty())
		    throw std::runtime_error("The list is empty!");
        return head->data;
    }

    //Iterator begin();
    //Iterator end();

    //void insert(Iterator at, const T& elem);

    ~DoublyLinkedList()
    {
        free();
    }
};

#endif