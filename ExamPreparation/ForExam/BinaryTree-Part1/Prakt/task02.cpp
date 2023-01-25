#include<iostream>
template <typename T>
struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;

    Node(T _data, Node<T> *_left = nullptr, Node<T> *_right = nullptr) : data(_data), left(_left), right(_right) {}
};
template <typename T>
void clear(Node<T>* tree)
{
    if (!tree)
        return;
    clear(tree->left);
    clear(tree->right);
    delete tree;
}
int getIndexMaxEl(int* listOfNumbers, size_t size)
{
    int id = 0;
    int maxEl = listOfNumbers[0];
    for (size_t i = 1; i < size; i++)
    {
        if (listOfNumbers[i] > maxEl)
        {
            maxEl = listOfNumbers[i];
            id = i;
        }
    }
    return id;
}
Node<int>* constructMaxBTree(int* listOfNumbers, size_t size)
{
    if (size == 0)
        return nullptr;

    int idMaxEl = getIndexMaxEl(listOfNumbers, size);
    return new Node<int>(listOfNumbers[idMaxEl], constructMaxBTree(listOfNumbers, idMaxEl), constructMaxBTree((listOfNumbers + idMaxEl + 1), size - idMaxEl - 1));
}
template <typename T>
void print(Node<T>* tree)
{
    if (!tree)
        return;
    std::cout << tree->data << ' ';
    print(tree->left);
    print(tree->right);
}
int main()
{
    int* listOfNumbers = new int[6];
    listOfNumbers[0] = 3;
    listOfNumbers[1] = 2;
    listOfNumbers[2] = 1;
    listOfNumbers[3] = 6;
    listOfNumbers[4] = 0;
    listOfNumbers[5] = 5;
    
    Node<int>* tree = constructMaxBTree(listOfNumbers, 6);

    print(tree);

    clear(tree);
    return 0;
}