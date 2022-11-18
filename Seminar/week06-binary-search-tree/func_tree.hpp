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
//task02
Node* insert(Node* tree, int el)
{
    if (!tree)
    {
        Node* newNode = new Node(el);
        return newNode;
    }

    if (el < tree->key)
        tree->left = insert(tree->left, el);
    else
        tree->right = insert(tree->right, el);
    
    return tree;
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
//task05
int LCA(Node* tree, int fstEl, int secEl)
{
    if (!isContains(tree, fstEl) || !isContains(tree, secEl))
        return -1;

    if(tree->key > std::max(fstEl,secEl))
        return LCA(tree->left, fstEl, secEl);
    else if(tree->key < std::min(fstEl,secEl))
        return LCA(tree->right, fstEl, secEl);

    return tree->key;
}
//task06
Node* remove(Node* tree, int key)
{
    if (tree == NULL)
        return tree;
  
    if (key < tree->key)
        tree->left = remove(tree->left, key);

    else if (key > tree->key)
        tree->right = remove(tree->right, key);
    else
    {
        if (!tree->left && !tree->right)
        {
            delete tree;
            return nullptr;
        }
        else if (!tree->left)
        {
            Node* newNode = tree->right;
            delete tree;
            return newNode;
        }
        else if (!tree->right)
        {
            Node* newNode = tree->left;
            delete tree;
            return newNode;
        }
        
        Node* temp = getMin(tree->right);

        tree->key = temp->key;

        tree->right = remove(tree->right, temp->key);
    }

    return tree;
}
//task07
int isBalance(Node* tree)
{
    if (tree == NULL)
        return 0;
    int lh = isBalance(tree->left);
    if (lh == -1)
        return -1;
    int rh = isBalance(tree->right);
    if (rh == -1)
        return -1;
 
    if (abs(lh - rh) > 1)
        return -1;
    else
        return std::max(lh, rh) + 1;
}

#endif