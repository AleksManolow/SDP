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
int getMinEl(Node* n)
{
    if (n->left->left == nullptr)
    {
        return n->left->key;
    }
    getMinEl(n->left);
}
int main()
{
    Node* tree = new Node(22);
    tree->left = new Node(12);
    tree->right = new Node(30);
    tree->left->left = new Node(8);
    tree->left->right = new Node(20);

    std::cout << getMinEl(tree) << std::endl;

    clean(tree);
}