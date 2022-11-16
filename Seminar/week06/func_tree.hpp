#ifndef __FUNC_TREE_HPP
#define __FUNC_TREE_HPP

struct Node
{
    int key;
    Node* left;
    Node* right;

    Node(int _key):key(_key), left(nullptr), right(nullptr){}
};
//task01
bool isContains(Node* tree, int value)
{
    if(!tree)
        return false;
    if(tree->key == value)
        return true;
    if(tree->key > value)
        return isContains(tree->left, value);
    return isContains(tree->right, value);
}
//task03
Node* getMin(Node* tree)
{
    if(!tree)
        return nullptr;
    if(!tree->left)
        return tree;
    return getMin(tree->left);
}
//task04
Node* getMax(Node* tree)
{
    if(!tree)
        return nullptr;
    if(!tree->right)
        return tree;
    return getMax(tree->right);
}

#endif