#include<iostream>
#include<vector>
#include <algorithm>
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int _data, Node* _left = nullptr, Node* _right = nullptr) : data(_data), left(_left), right(_right) {}
};
void clear(Node* tree)
{
    if (!tree)
        return;
    clear(tree->left);
    clear(tree->right);
    delete tree;
}
int height(Node* tree)
{
    if (!tree)
        return 0;
    return 1 + std::max(height(tree->left), height(tree->right));
}
void getElOnLevel(Node* tree, int level, std::vector<int>& elements)
{
    if(!tree)
        return;
    if (level == 0)
        elements.push_back(tree->data);

    getElOnLevel(tree->left, level - 1, elements);
    getElOnLevel(tree->right, level - 1, elements);

}
bool checkElementOnLevel(Node* treeA, Node* treeB)
{    
    if (height(treeA) != height(treeB))
        return false;

    for (size_t i = 0; i < height(treeA); i++)
    {
        std::vector<int> elOnLvTreeA;
        std::vector<int> elOnLvTreeB;

        getElOnLevel(treeA, i, elOnLvTreeA);
        getElOnLevel(treeB, i, elOnLvTreeB);

        if (elOnLvTreeA.size() != elOnLvTreeB.size())
            return false;
        
        for (size_t i = 0; i < elOnLvTreeA.size(); i++)
        {
            if (std::find(elOnLvTreeB.begin(), elOnLvTreeB.end(), elOnLvTreeA[i]) == elOnLvTreeB.end())
                return false;
        }
    }
    return true;
}
int main ()
{
    Node* treeA = new Node(3);
    treeA->left = new Node(-312);
    treeA->right = new Node(65);
    treeA->left->left = new Node(123);
    treeA->left->left->left = new Node(-7);
    treeA->left->left->right = new Node(16);
    treeA->right->left = new Node(14);
    treeA->right->left->left = new Node(4);
    treeA->right->right = new Node(-31);
    treeA->right->right->left = new Node(-91);
    treeA->right->right->right = new Node(16);

    Node* treeB = new Node(3);
    treeB->left = new Node(65);
    treeB->left->left = new Node(123);
    treeB->left->left->left = new Node(-91);
    treeB->left->right  = new Node(-31);
    treeB->left->right->left = new Node(16);
    treeB->left->right->right = new Node(16);
    treeB->right = new Node(-312);
    treeB->right->right = new Node(14);
    treeB->right->right->left = new Node(-7);
    treeB->right->right->right = new Node(4);
    
    std::cout << checkElementOnLevel(treeA, treeB) << std::endl; 

    clear(treeA);
    clear(treeB);
    return 0;
}