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



#endif