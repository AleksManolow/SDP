#include<iostream>
struct Node
{
    std::pair<int, int > data;
    Node* left;
    Node* right;

    Node(std::pair<int, int > _data, Node* _left = nullptr, Node* _right = nullptr):data(_data), left(_left), right(_right) {   }
};
void clear(Node* tree)
{
    if (!tree)
        return;
    clear(tree->left);
    clear(tree->right);
    delete tree;
}
void print(Node* tree)
{
    if (!tree)
        return;
    std::cout << '(' << tree->data.first << '-' << tree->data.second << ')' << ' '; 
    print(tree->left);
    print(tree->right);
}
bool ordered(Node* tree)
{
    if (!tree->left && !tree->right)
        return true;
    
    if (!tree->left)
        return (tree->data.second - tree->data.first) < (tree->right->data.second - tree->right->data.first) && ordered(tree->right);
    if (!tree->right)
        return (tree->data.second - tree->data.first) > (tree->left->data.second - tree->left->data.first) && ordered(tree->left);
    
    return (tree->data.second - tree->data.first) < (tree->right->data.second - tree->right->data.first)
        && (tree->data.second - tree->data.first) > (tree->left->data.second - tree->left->data.first)
        && ordered(tree->left) && ordered(tree->right);
}
int main()
{
    Node* treeA = new Node(std::pair<int, int>(3, 10));
    treeA->left = new Node(std::pair<int, int>(5, 8));
    treeA->right = new Node(std::pair<int, int>(2, 12));
    treeA->left->left = new Node(std::pair<int, int>(6, 7));
    treeA->left->right = new Node(std::pair<int, int>(4, 9));
    treeA->right->right = new Node(std::pair<int, int>(1, 15));

    Node* treeB = new Node(std::pair<int, int>(3, 10));
    treeB->left = new Node(std::pair<int, int>(5, 8));
    treeB->right = new Node(std::pair<int, int>(2, 12));
    treeB->left->left = new Node(std::pair<int, int>(6, 7));
    treeB->left->right = new Node(std::pair<int, int>(7, 9));
    treeB->right->right = new Node(std::pair<int, int>(1, 15));

    print(treeA);
    std::cout << std::endl;
    print(treeB);
    std::cout << std::endl;
    
    std::cout << ordered(treeA) << std::endl;
    std::cout << ordered(treeB) << std::endl;

    clear(treeA);
    clear(treeB);
    return 0;
}