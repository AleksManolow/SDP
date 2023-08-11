#include<iostream>
#include<vector>
struct Node
{
    int key;
    Node* left;
    Node* right;

    Node(int _key):key(_key), left(nullptr), right(nullptr){}
};
void clean(Node*& n) {
    if (n == nullptr) return;
    clean(n->left);
    clean(n->right);
    delete n;
}
int isSumProperty(Node* node)
{
    int sum = 0;
 
    if (node == nullptr || (node->left == nullptr && node->right == nullptr))
        return 1;
    else 
    {
        if (node->left != nullptr)
            sum += node->left->key;
 
        if (node->right != nullptr)
            sum += node->right->key;
 
        return ((node->key == sum)
                && isSumProperty(node->left)
                && isSumProperty(node->right));
    }
}
int main()
{
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(2);

    std::cout << isSumProperty(root) << std::endl;
    
    clean(root);
}