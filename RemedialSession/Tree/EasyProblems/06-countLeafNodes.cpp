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
int getLeafCount(Node* tree)
{
    if(tree == nullptr)    
        return 0;

    if (tree->left == nullptr && tree->right == nullptr)
    {
        return 1;
    }    
    return getLeafCount(tree->left) + getLeafCount(tree->right);
}
int main()
{
    Node* tree = new Node(22);
    tree->left = new Node(12);
    tree->right = new Node(30);
    tree->left->left = new Node(8);
    tree->left->right = new Node(20);
    tree->right->right = new Node(25);
    tree->right->left = new Node(27);

    std::cout << getLeafCount(tree) << std::endl;

    clean(tree);
}