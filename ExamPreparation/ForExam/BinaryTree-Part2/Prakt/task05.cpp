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
int sumTree(Node* tree)
{
    if (!tree)
        return 0;
    return tree->data + sumTree(tree->left) + sumTree(tree->right);
}
int maxSumSubT(Node* tree)
{
    if (!tree)
        return 0;
    return std::max(sumTree(tree), std::max(maxSumSubT(tree->left), maxSumSubT(tree->right)));
}
int main()
{
    Node* t1 = new Node(3);
    t1->left = new Node(0);
    t1->right = new Node(2);
    t1->right->left = new Node(0);

    Node* t2 = new Node(-3);
    t2->left = new Node(0);
    t2->right = new Node(2);
    t2->right->left = new Node(0);

    std::cout << maxSumSubT(t1) << std::endl;
    std::cout << maxSumSubT(t2) << std::endl;

    clear(t1);
    clear(t2);

    return 0;
}