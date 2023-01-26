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
template <typename T>
int hight(Node<T>* tree)
{
    if (!tree)
        return 0;
    return 1 + std::max(hight(tree->left), hight(tree->right));
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
double average(Node<T>* tree)
{
    return sumTree(tree) / (double)size(tree);
}
template <typename T>
bool areEqual(Node<T>* treeA, Node<T>* treeB)
{
    if (!treeA && !treeB)
        return true;
    if (treeA != nullptr && treeB != nullptr)
        return (treeA->data == treeB->data) && areEqual(treeA->left, treeB->left) && areEqual(treeA->right, treeB->right);
    return false;
}
template <typename T>
bool isMirror(Node<T>* treeL, Node<T>* treeR)
{
    if (treeL == nullptr && treeR == nullptr)
        return true;

    if (treeL && treeR && treeL->data == treeR->data)
        return isMirror(treeL->left, treeR->right)
               && isMirror(treeL->right, treeR->left); 
    return false;
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

    //number of nodes along the longest branch
    std::cout << hight(numberBTree) << std::endl;
    std::cout << hight(charBTree) << std::endl;

    //returns the average of the nodes
    std::cout << average(numberBTree) << std::endl;

    //are equal
    std::cout << areEqual(numberBTree, numberBTree) << std::endl;

    //mirror tree 
    std::cout << isMirror(numberBTree->left, numberBTree->right) << std::endl;

    clear(numberBTree);
    clear(charBTree);

    return 0;
}