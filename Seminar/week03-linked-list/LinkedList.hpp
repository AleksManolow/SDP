#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template<typename T>
struct Node
{
    T key;
    Node<T> *next;
    Node(T key) : key(key), next(nullptr){};
};

template<typename T>
class LinkedList
{
private:
    Node<T> *front;
    size_t size;
public:
    LinkedList(){   front = nullptr;    size = 0;}
    ~LinkedList()
    {
        Node<T>* temp; 
        while (front != nullptr)
        {
            temp = front;
            front = front->next;
            delete temp;
        }
        size = 0;
    }
    // LinkedList(const LinkedList<T>& other) {
        
    // }
    // bool operator==(const LinkedList<T>& other) const {
    // }
    // LinkedList<T>& operator=(const LinkedList<T>& other) {
    // }
    void insertAtPos(T a, std::size_t pos = 0);
    void removeAtPos(std::size_t pos = 0);
    const T& getElementAtPos(unsigned pos);
    T& top() const;
    void printList();
    std::size_t getSize() { return size;    }
    // void sort() 
    // { // sort based on operator <
        
    // }
	// struct Iterator 
    // { // can this be also class?
	// 	Iterator() : current(nullptr) {};
	// 	Iterator(Node<T>* _current) : current(_current){};
	// 	friend bool operator==(const Iterator& a, const Iterator& b) {
	// 		return a.current == b.current;
	// 	}
	// 	friend bool operator!=(const Iterator& a, const Iterator& b) {
	// 		return a.current != b.current;
	// 	}
	// 	T& operator*() const {}
	// 	Iterator& operator++() {}
	// 	Iterator operator++(int) {}
	// private:
	// 	Node<T>* current;
	// };

	// Iterator begin() {return Iterator();}
	// Iterator end() {return Iterator();} // is there a way to know this value?
};

template<typename T>
void LinkedList<T>::insertAtPos(T a, std::size_t pos = 0) 
{
        
    if ((pos < 0) || (pos > size + 1))
    {
        std::cout << "Error: the given position is out of range." << std::endl;
        return;
    }
    if (front == nullptr)
    {
        Node<T>* newNode = new Node<T>(a);
        front = newNode;
        size++;
        std::cout << "Success added!" << std::endl;
        return;
    }

    if (pos == 0)
    {
        Node<T>* newNode = new Node<T>(a);
        newNode->next = front;
        front = newNode;
        size++;
        std::cout << "Success added on position 0!" << std::endl;
        return;
    }
        
    int count = 0;
    Node<T> *p = front;
    Node<T> *q = front;

    while (q != nullptr)
    {
        if (count == pos)
        {
            Node<T>* newNode = new Node<T>(a);
            p->next = newNode;
            newNode->next = q;
            size++;
            std::cout << "Success added!" << std::endl;
            return;
        }
        p = q;
        q = p->next;
        count++;
    }

    if (count == pos)
    {
        Node<T>* newNode = new Node<T>(a);
        p->next = newNode;
        newNode->next = q;
        size++;
        std::cout << "Success added!" << std::endl;
        return;
    }

    std::cout << "Faild added!" << std::endl;
}

template<typename T>
void LinkedList<T>::removeAtPos(std::size_t pos = 0) 
{
    if ((pos < 0) || (pos > size))
    {
        std::cout << "Error: the given position is out of range." << std::endl;
        return;
    }

    if (!front->next)
    {
        std::cout << "Error: there is nothing to remove." << std::endl;
        return;
    }
        
    int count = 0;
    Node<T> *p = front;
    Node<T> *q = front;
    while (q)
    {
            if (count == pos)
        {
            p -> next = q -> next;
            delete q;
            size--;
            std::cout << "Success remove at position!"<< std::endl;
            return;
        }
        p = q;
        q = p -> next;
        count++;
    }
}

template<typename T>
const T& LinkedList<T>::getElementAtPos(unsigned pos) 
{
    int count = 0;
    Node<T> *p = front;
    Node<T> *q = front;
    while (q)
    {
        if (count == pos)
        {
            return q->key;
        }
        p = q;
        q = p -> next;
        count++;
    }
    return -1;
}

template<typename T>
T& LinkedList<T>::top() const 
{
    return front->key;
}

template<typename T>
void LinkedList<T>::printList()
{
    int count = 0;
    Node<T>* p = front;
    Node<T>* q = front;
    while (q != nullptr)
    {
        p = q;
        std::cout << "Position: " << count << std::endl;
        std::cout << "Date:" << p->key << std::endl;
        q = p->next;
        count++;
    }
}

#endif

