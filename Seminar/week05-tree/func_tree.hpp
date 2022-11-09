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
int countElements(Node* tree)
{
    if (tree == nullptr)
        return 0;
    return 1 + countElements(tree->left) + countElements(tree->right);
}
//task02
int countLeafs(Node* tree)
{
    if (tree == nullptr)
        return 0;
    if (tree->left == nullptr && tree->right == nullptr)
        return 1;
    return countLeafs(tree->left) + countLeafs(tree->right);
}
//task03
int height(Node* tree)
{
    if (tree == nullptr)
        return 0;
    return 1 + std::max(height(tree->left), height(tree->right));
}
//task04
int sumElements(Node* tree)
{
    if (tree == nullptr)
        return 0;
    return tree->key + sumElements(tree->left) + sumElements(tree->right);
}
//task05
int sumElementsAtLevel(Node* tree, unsigned level)
{
    if (tree == nullptr)
        return 0;
    if (level == 0)
        return tree->key;    
    return sumElementsAtLevel(tree->left, level - 1) + sumElementsAtLevel(tree->right, level - 1);
}
//task06
bool isMirror(Node* treeL, Node* treeR)
{
    if (treeL == nullptr && treeR == nullptr)
        return true;

    if (treeL && treeR && treeL->key == treeR->key)
        return isMirror(treeL->left, treeR->right)
               && isMirror(treeL->right, treeR->left); 
    return false;
}
bool isSymmetric(Node* tree)
{
    return isMirror(tree, tree);
}



#endif