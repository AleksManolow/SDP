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
void printRoot(int treeRoot[], int pathLen)
{
    for (int i = 0; i < pathLen; i++)
    {
        std::cout << treeRoot[i] << " ";
    }
    std::cout << std::endl;
}
void printPathsRecur(Node* tree, int root[], int pathLen)
{

    if(tree == nullptr)
    { 
        return;
    }

    root[pathLen] = tree->key; 
    pathLen++; 
    
    if(tree->left == nullptr && tree->right == nullptr)
    {
        printRoot(root, pathLen);
    }
    else
    {
        printPathsRecur(tree->left, root, pathLen);
        printPathsRecur(tree->right, root, pathLen);
    }
}
int main()
{
    Node* tree = new Node(1);
    tree->left = new Node(2);
    tree->right = new Node(3);
    tree->left->left = new Node(4);
    tree->left->right = new Node(5);

    int root[1000];
    printPathsRecur(tree, root, 0);

    clean(tree);
}