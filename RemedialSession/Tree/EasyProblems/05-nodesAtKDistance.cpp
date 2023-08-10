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
void printKDistant(Node* tree, int k)
{
    if (tree == nullptr || k < 0)
    {
        return;
    }

    if (k == 0)
    {
        std::cout << tree->key << " ";
    }
    
    printKDistant(tree->left, k - 1);
    printKDistant(tree->right, k - 1);
}
int main()
{
    Node* tree = new Node(22);
    tree->left = new Node(12);
    tree->right = new Node(30);
    tree->left->left = new Node(8);
    tree->left->right = new Node(20);
    tree->right->right = new Node(25);

    printKDistant(tree, 2);

    clean(tree);
}