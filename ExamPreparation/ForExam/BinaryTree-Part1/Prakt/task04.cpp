#include<iostream>
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int _data, Node *_left = nullptr, Node *_right = nullptr) : data(_data), left(_left), right(_right) {}
};
void clean(Node*& n) {
    if (n == nullptr) return;
    clean(n->left);
    clean(n->right);
    delete n;
}
bool isBinarySearchTree(Node* tree)
{
    if (tree->left == nullptr && tree->right == nullptr)
        return true;
    if (tree->left == nullptr)
        return (tree->data < tree->right->data) && isBinarySearchTree(tree->right);
    if (tree->right == nullptr)
        return (tree->data > tree->left->data) && isBinarySearchTree(tree->left);
    return (tree->data > tree->left->data) && isBinarySearchTree(tree->left) && (tree->data < tree->right->data) && isBinarySearchTree(tree->right);
} 
int main()
{
    Node* test = new Node(100);
    test->left = new Node(50);
    test->right = new Node(140);
    test->left->left = new Node(25);

    std::cout << isBinarySearchTree(test) << std::endl;

    clean(test);

    return 0;
}