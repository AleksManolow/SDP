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
bool contains(Node* tree, int value)
{
    if (!tree)
        return false;
    if (tree->key == value)
        return true;
    if (tree->key > value)
        return contains(tree->left, value);
    return contains(tree->right, value);
}
int main()
{
    Node* test = new Node(100);
    test->left = new Node(50);
    test->right = new Node(140);
    test->left->left = new Node(25);

    std::cout << ((contains(test, 140) == true) ? "True" : "False") << std::endl;
    std::cout << ((contains(test, 25) == true) ? "True" : "False") << std::endl;
    std::cout << ((contains(test, 0) == false) ? "True" : "False") << std::endl;
    std::cout << ((contains(test, 150) == false) ? "True" : "False") << std::endl;
    clean(test);
    return 0;
}