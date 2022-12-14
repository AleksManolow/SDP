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
Node* insert(Node* tree, int el)
{
    if (!tree)
    {
        Node* newNode = new Node(el);
        return newNode;
    }
    if (el < tree->key)
        tree->left = insert(tree->left, el);
    else
        tree->right = insert(tree->right, el);
    
    return tree;
}
int main()
{
    Node* test = new Node(100);
    test->left = new Node(50);
    test->right = new Node(140);
    test->left->left = new Node(25);
    test = insert(test, 150);
    std::cout << ((test->right->right->key == 150) ? "True" : "False") << std::endl;
    test = insert(test, 75);
    std::cout << ((test->left->right->key == 75) ? "True" : "False")<< std::endl;

    clean(test);
    return 0;
}