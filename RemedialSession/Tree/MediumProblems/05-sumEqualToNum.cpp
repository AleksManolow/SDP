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
bool hasPathSum(Node* node, int sum)
{
    if (node == nullptr)
    {
        if (sum == 0)
            return true;
        else
            return false;
    }   
    
    return hasPathSum(node->left, sum - node->key) || hasPathSum(node->right, sum - node->key);
}
int main()
{
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(2);

    std::cout << hasPathSum(root, 23) << std::endl;
    
    clean(root);
}