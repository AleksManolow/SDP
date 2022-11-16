#ifndef __FUNC_TREE_HPP
#define __FUNC_TREE_HPP

struct Node
{
    int key;
    Node* left;
    Node* right;

    Node(int _key):key(_key), left(nullptr), right(nullptr){}
};

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
    return tree;
}

#endif