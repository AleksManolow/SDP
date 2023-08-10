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
int getMaxHight(Node* n)
{
    if (n == nullptr)
    {
        return 0;
    }
    return 1 + std::max(getMaxHight(n->left), getMaxHight(n->right));
}
int main()
{
    Node* tree = new Node(22);
    tree->left = new Node(12);
    tree->right = new Node(30);
    tree->left->left = new Node(8);
    //tree->left->right = new Node(20);

    std::cout << getMaxHight(tree) << std::endl;

    clean(tree);
}