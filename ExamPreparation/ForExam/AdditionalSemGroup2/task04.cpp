#include<iostream>
struct Node
{
    char data;
    Node *left;
    Node *right;

    Node(char _data, Node* _left = nullptr, Node* _right = nullptr) : data(_data), left(_left), right(_right) {}
};
void clear(Node* tree)
{
    if (!tree)
        return;
    clear(tree->left);
    clear(tree->right);
    delete tree;
}
int calculate(Node* tree)
{
    if (!tree->left && !tree->right)
        return int(tree->data) - 48;
    switch (tree->data)
    {
    case '+':
        return calculate(tree->left) + calculate(tree->right);
    case '-':
        return calculate(tree->left) - calculate(tree->right);
    case '*':
        return calculate(tree->left) * calculate(tree->right);
    case '/':
        return calculate(tree->left) / calculate(tree->right);
    }
}
int main()
{   
    Node* tree = new Node('+');
    tree->left = new Node('3');
    tree->right = new Node('*');
    tree->right->left = new Node('+');
    tree->right->right = new Node('2');
    tree->right->left->left = new Node('5');
    tree->right->left->right = new Node('9');


    std::cout << calculate(tree) << std::endl;

    clear(tree);

    return 0;
}