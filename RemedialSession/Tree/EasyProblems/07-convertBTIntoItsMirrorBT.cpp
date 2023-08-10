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
void printTree(Node* tree)
{
    if (tree == nullptr)
        return; 

    printTree(tree->left);
    std::cout << tree->key << " ";
    printTree(tree->right);
}
void mirrorBT(Node* tree)
{
    if (tree == nullptr)
    {
        return;
    }
    
    Node* temp = tree->left;
    tree->left = tree->right;
    tree->right = temp;

    mirrorBT(tree->left);
    mirrorBT(tree->right);
}
int main()
{
    Node* tree = new Node(1);
    tree->left = new Node(2);
    tree->right = new Node(3);
    tree->left->left = new Node(4);
    tree->left->right = new Node(5);


    printTree(tree);

    std::cout << std::endl;

    mirrorBT(tree);

    printTree(tree);

    clean(tree);
}