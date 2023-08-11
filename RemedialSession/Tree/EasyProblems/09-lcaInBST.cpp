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
Node* LCA(Node* tree, int n1, int n2)
{

     if (tree == nullptr)
        return nullptr;
 
    if (tree->key > n1 && tree->key > n2)
        return LCA(tree->left, n1, n2);
 
    // If both n1 and n2 are greater than
    // root, then LCA lies in right
    if (tree->key < n1 && tree->key < n2)
        return LCA(tree->right, n1, n2);
 
    return tree;
}
int main()
{
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    int n1 = 10, n2 = 14;
    Node* t = LCA(root, n1, n2);
    std::cout << "LCA of " << n1 << " and " << n2 << " is "
         << t->key << std::endl;
 
    n1 = 14, n2 = 8;
    t = LCA(root, n1, n2);
    std::cout << "LCA of " << n1 << " and " << n2 << " is "
         << t->key << std::endl;
 
    n1 = 10, n2 = 22;
    t = LCA(root, n1, n2);
    std::cout << "LCA of " << n1 << " and " << n2 << " is "
         << t->key << std::endl;

    clean(root);
}