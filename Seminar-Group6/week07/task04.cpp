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
int height(Node* tree)
{
    if(tree == nullptr)
        return 0;
    return 1 + std::max(height(tree->left),height(tree->right));
}
int main()
{
    Node* test = new Node(5);
    test->left = new Node(7);
    test->right = new Node(7);
    test->left->left = new Node(14);
    test->left->left->right = new Node(18);

    std::cout << height(test) << std::endl;
    
    clean(test);

    return 0;
}