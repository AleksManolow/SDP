#include<iostream>
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int _data, Node* _left = nullptr, Node* _right = nullptr) : data(_data), left(_left), right(_right) { }
};
void clear(Node* tree)
{
    if (!tree)
        return;
    clear(tree->left);
    clear(tree->right);
    delete tree;
}
int rangedSum(Node* treeA, int L, int R)
{
    if(!treeA)
        return 0;
    if (treeA->data >= std::min(L, R) && treeA->data <= std::max(L, R))
        return treeA->data + rangedSum(treeA->left, L, R) + rangedSum(treeA->right, L, R);
    return rangedSum(treeA->left, L, R) + rangedSum(treeA->right, L, R);
}
int main()
{
    Node* treeA = new Node(10);
    treeA->left = new Node(5);
    treeA->right = new Node(15);
    treeA->left->left = new Node(3);
    treeA->left->right = new Node(7);
    treeA->right->right = new Node(18);

    Node* treeB = new Node(10);
    treeB->left = new Node(5);
    treeB->right = new Node(15);
    treeB->left->left = new Node(3);
    treeB->left->left->left = new Node(1);
    treeB->left->right = new Node(7);
    treeB->left->right->left = new Node(6);
    treeB->right->right = new Node(18);
    treeB->right->left = new Node(13);

    std::cout << rangedSum(treeA, 100, 50) << std::endl;
    std::cout << rangedSum(treeA, 7, 15) << std::endl;
    std::cout << rangedSum(treeA, 15, 7) << std::endl;
    std::cout << rangedSum(treeB, 6, 10) << std::endl;
    std::cout << rangedSum(treeB, 10, 6) << std::endl;

    clear(treeA);
    clear(treeB);
    return 0;
}