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
//task07
bool isBST(Node* tree)
{
    if (tree->left == nullptr && tree->right == nullptr)
        return true;
    if (tree->left == nullptr)
        return (tree->key < tree->right->key) && isBST(tree->right);
    if (tree->right == nullptr)
        return (tree->key > tree->left->key) && isBST(tree->left);
    return (tree->key > tree->left->key) && isBST(tree->left) && (tree->key < tree->right->key) && isBST(tree->right);
}
//task08
void inorder(Node* tree,std::vector<int>& inorderOrder)
{
    if (tree == NULL)
        return;

    inorder(tree -> left, inorderOrder);
    inorderOrder.push_back(tree -> key);
    inorder(tree -> right, inorderOrder);
}
void preorder(Node* tree,std::vector<int>& preorderOrder)
{
    if (tree == NULL)
        return;

    preorderOrder.push_back(tree -> key);
    preorder(tree -> left, preorderOrder);
    preorder(tree -> right, preorderOrder);
}
void postorder(Node* tree,std::vector<int>& postorderOrder)
{
    if (tree == NULL)
        return;
    postorder(tree -> left, postorderOrder);
    postorder(tree -> right, postorderOrder);
    postorderOrder.push_back(tree -> key);
}
#endif