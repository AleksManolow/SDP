#include<iostream>
struct Node
{
    int key;
    Node* left;
    Node* right;

    Node(int _key):key(_key), left(nullptr), right(nullptr){}
};
void clean(Node*& n) {
    if (n == nullptr) return;
    clean(n->left);
    clean(n->right);
    delete n;
}
int countElements(Node* tree)
{
    if (tree == nullptr)
        return 0;
    return 1 + countElements(tree->left) + countElements(tree->right);
}
int main()
{
    Node* tree = new Node(5);
    tree->left = new Node(7);
    tree->right = new Node(7);
    tree->left->left = new Node(14);

    std::cout << countElements(tree) << std::endl;

    clean(tree);
}