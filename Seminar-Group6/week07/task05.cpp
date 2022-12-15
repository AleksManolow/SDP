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
void inorderTraversal(Node* tree)
{
    if(tree == nullptr)
        return;
    inorderTraversal(tree->left);
    std::cout << tree->key << " ";
    inorderTraversal(tree->right);
}
int main()
{
    Node* test = new Node(100);
    test->left = new Node(50);
    test->right = new Node(140);
    test->left->left = new Node(25);

    inorderTraversal(test);

    clean(test);
    return 0;
}