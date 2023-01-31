#include<iostream>
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int _data, Node* _left = nullptr, Node* _right = nullptr) : data(_data), left(_left), right(_right) {}
};
void clear(Node* tree)
{
    if (!tree)
        return;
    clear(tree->left);
    clear(tree->right);
    delete tree;
}
Node* insert(Node* tree, int el)
{
    if (!tree)
        return new Node(el);
    if (el > tree->data)
        tree->right = insert(tree->right, el);
    else
        tree->left = insert(tree->left, el);
    return tree;
}
void print(Node* tree)
{
    if (!tree)
        return;
    std::cout << tree->data << ' '; 
    print(tree->left);
    print(tree->right);
}
int main()
{
    Node* tree = new Node(10);
    tree->left = new Node(5);
    tree->right = new Node(15);
    tree->left->left = new Node(3);
    tree->left->right = new Node(7);
    tree->right->right = new Node(18);

    Node* treeTest = insert(tree, 13);

    print(treeTest);

    return 0;
}