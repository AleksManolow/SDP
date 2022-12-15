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
int max_elem(Node* tree)
{
    int res = tree->key;

    if (tree->left != nullptr)
    {
        res = std::max(res,max_elem(tree->left));
    }
    if (tree->right != nullptr)
    {
        res = std::max(res,max_elem(tree->right));
    }
    return res;
}
int min_elem(Node* tree)
{
    int res = tree->key;

    if (tree->left != nullptr)
    {
        res = std::min(res, min_elem(tree->left));
    }
    if (tree->right != nullptr)
    {
        res = std::min(res, min_elem(tree->right));
    }
    return res;
}
int main()
{
    Node* test = new Node(100);
    test->left = new Node(50);
    test->right = new Node(140);
    test->left->left = new Node(25);

    std::cout << max_elem(test) << std::endl;
    std::cout << min_elem(test) << std::endl;
    
    clean(test);
    return 0;
}