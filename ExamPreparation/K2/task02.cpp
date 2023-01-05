#include<iostream>
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int _data, Node* _left = nullptr, Node* _right = nullptr):data(_data), left(_left), right(_right){}
};
int height(Node* node)
{
    if (node == nullptr)
        return 0;

    int lheight = height(node->left);
    int rheight = height(node->right);

    if (lheight > rheight) {
        return (lheight + 1);
    }
    else {
        return (rheight + 1);
    }
}
void printCurrentLevel(Node* root, int level)
{
    if (root == nullptr)
        return;
    if (level == 1)
        std::cout << root->data << " ";
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}
void printLevelOrder(Node* root)
{
    int h = height(root);
    for (int i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
void clean(Node*& n) {
    if (n == nullptr) return;
    clean(n->left);
    clean(n->right);
    delete n;
}
int main()
{
    Node* tree = new Node(20);
    tree->left = new Node(8);
    tree->left->left = new Node(4);
    tree->left->right = new Node(12); 
    tree->right = new Node(22);
    tree->left->right->left = new Node(10);
    tree->left->right->right = new Node(14); 

    printLevelOrder(tree);

    clean(tree);

    return 0;
}