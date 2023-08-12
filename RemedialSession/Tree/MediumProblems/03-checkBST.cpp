#include<iostream>
#include<vector>
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
int getMaxEl(Node* tree)
{
    if (tree == nullptr)
        return INT16_MIN;
    
    return std::max(tree->key,std::max(getMaxEl(tree->left), getMaxEl(tree->right)));
}
int getMinEl(Node* tree)
{
    if (tree == nullptr)
        return INT16_MAX;
    
    return std::min(tree->key,std::min(getMinEl(tree->left), getMinEl(tree->right)));
}
bool isBST(Node* tree)
{
    if (tree == nullptr)
        return true;
    
    if (getMinEl(tree->right) < tree->key || getMaxEl(tree->left) > tree->key)
        return false;
    
    return isBST(tree->left) && isBST(tree->right);
}
int main()
{
    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(12);
    root->left->left = new Node(1);
    root->left->right = new Node(11);
    root->right->right = new Node(14);

    std::cout << isBST(root) << std::endl;
    
    clean(root);
}