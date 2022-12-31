#include<iostream>
struct Node
{
    int key;
    Node* left;
    Node* right;

    Node(int _key):key(_key), left(nullptr), right(nullptr){}
};
bool isContains(Node* tree, int value)
{
    if(!tree)
        return false;
    if(tree->key == value)
        return true;
    if(tree->key > value)
        return isContains(tree->left, value);
    return isContains(tree->right, value);
}
void clean(Node*& n) {
    if (n == nullptr) return;
    clean(n->left);
    clean(n->right);
    delete n;
}
int main()
{
    Node* test = new Node(100);
    test->left = new Node(50);
    test->right = new Node(140);
    test->left->left = new Node(25);

    std::cout << (isContains(test, 140) == true) << std::endl;
    std::cout << (isContains(test, 25) == true) << std::endl;
    std::cout << (isContains(test, 0) == false) << std::endl;
    std::cout << (isContains(test, 150) == false) << std::endl;
    clean(test); 

    return 0;
}