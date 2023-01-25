#include <iostream>
template <typename T>
struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;

    Node(T _data, Node<T> *_left = nullptr, Node<T> *_right = nullptr) : data(_data), left(_left), right(_right) {}
};
template <typename T>
void clear(Node<T> *tree)
{
    if (!tree)
        return;
    clear(tree->left);
    clear(tree->right);
    delete tree;
}
template <typename T>
int size(Node<T> *tree)
{
    if (!tree)
        return 0;
    return 1 + size(tree->left) + size(tree->right);
}
template <typename T>
T sumTree(Node<T> *tree)
{
    if (!tree)
        return 0;
    return tree->data + sumTree(tree->left) + sumTree(tree->right);
}
template <typename T>
void printDFS(Node<T>* tree)
{
    if (!tree)
        return;
    printDFS(tree->left);
    std::cout << tree->data << ' ';
    printDFS(tree->right);
}
template <typename T>
void getLevel(Node<T> *tree, int k)
{
    if (!tree)
        return;

    if (k == 0)
    {
        std::cout << tree->data << ' ';
        return;
    }
    getLevel(tree->left, k - 1);
    getLevel(tree->right, k - 1);
}
template <typename T>
void printBFS(Node<T>* tree)
{
    for (size_t i = 0; i < 5; i++)
    {
        getLevel(tree, i);
    }
}
int main()
{
    Node<int> *numberBTree = new Node<int>(5);
    numberBTree->left = new Node<int>(12);
    numberBTree->right = new Node<int>(4);
    numberBTree->left->left = new Node<int>(1);
    numberBTree->left->right = new Node<int>(0);
    numberBTree->left->left->left = new Node<int>(96);
    numberBTree->right->left = new Node<int>(2);
    numberBTree->right->right = new Node<int>(5);
    numberBTree->right->right->right = new Node<int>(21);

    Node<char> *charBTree = new Node<char>('k');
    charBTree->left = new Node<char>('a');
    charBTree->right = new Node<char>('l');
    charBTree->left->left = new Node<char>('h');
    charBTree->left->right = new Node<char>('s');
    charBTree->right->left = new Node<char>('e');
    charBTree->right->right = new Node<char>('l');

    // Size tree
    std::cout << size(numberBTree) << std::endl;
    std::cout << size(charBTree) << std::endl;

    // The sum of the nodes
    std::cout << sumTree(numberBTree) << std::endl;

    // Prints the nodes using DFS;
    printDFS(numberBTree);
    std::cout << std::endl;
    printDFS(charBTree);
    std::cout << std::endl;

    // accepts a whole number k and returns the nodes at level k
    getLevel(numberBTree, 2);
    std::cout << std::endl;
    getLevel(charBTree, 1);
    std::cout << std::endl;

    //prints the nodes using BFS
    printBFS(numberBTree);
    std::cout << std::endl;
    printBFS(charBTree);
    std::cout << std::endl;

    clear(numberBTree);
    clear(charBTree);

    return 0;
}