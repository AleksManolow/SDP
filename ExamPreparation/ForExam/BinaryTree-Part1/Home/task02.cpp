#include<iostream>
#include<string>
struct Node
{
    std::string data;
    Node *left;
    Node *right;

    Node(std::string _data, Node *_left = nullptr, Node *_right = nullptr) : data(_data), left(_left), right(_right) {}
};
void clean(Node*& n) {
    if (n == nullptr) return;
    clean(n->left);
    clean(n->right);
    delete n;
}
int hight(Node* tree)
{
    if (!tree)
        return 0;
    return 1 + std::max(hight(tree->left), hight(tree->right));
}
bool checkColourFromLevel(std::string colour, Node* colourBTree, int k)
{
    if (!colourBTree)
        return false;
    if (colourBTree->data == colour && k == 1)
        return true;
    if (k == 1)
        return false;

    return checkColourFromLevel(colour, colourBTree->left, k - 1) || checkColourFromLevel(colour, colourBTree->right, k - 1);
}
int highest(std::string colour, Node* colourBTree)
{
    int highestColour = -1;
    for (size_t i = 1; i <= hight(colourBTree); i++)
    {
        if (checkColourFromLevel(colour, colourBTree, i))
        {
            highestColour = i;
        }
    }
    return highestColour;
}
int main()
{
    Node* colourBTree = new Node("Blue");
    colourBTree->left = new Node("Green");
    colourBTree->right = new Node("Red");
    colourBTree->left->left = new Node("Blue");
    colourBTree->left->right = new Node("Blue");
    colourBTree->left->left->left = new Node("Red");
    colourBTree->right->left = new Node("Green");
    colourBTree->right->right = new Node("Red");
    colourBTree->right->left->left = new Node("Blue");

    std::cout << highest("Red", colourBTree) << std::endl;
    std::cout << highest("Green", colourBTree) << std::endl;
    std::cout << highest("Blue", colourBTree) << std::endl;

    return 0;
}