#include<iostream>
struct Node
{
    int key;
    Node* left;
    Node* right;

    Node(int _key, Node* _left = nullptr, Node* _right = nullptr):key(_key), left(_left), right(_right){}
};
Node* getMin(Node* tree)
{
    if(!tree)
        return nullptr;
    if(!tree->left)
        return tree;
    return getMin(tree->left);
}
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
void clean(Node*& n) {
    if (n == nullptr) return;
    clean(n->left);
    clean(n->right);
    delete n;
}
int main()
{
    Node* test = new Node(100);
    test->left = new Node(50);
    test->right = new Node(140);
    test->left->left = new Node(25);
    test = remove(test, 25);
    std::cout << (test->left->left == nullptr) << std::endl;
    test = remove(test, 100);
    std::cout << (test->key == 140) << std::endl;
    std::cout << (test->right == nullptr) << std::endl;
    
    clean(test);

    return 0;
}