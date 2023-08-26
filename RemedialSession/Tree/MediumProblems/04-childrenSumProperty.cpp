#include<bits/stdc++.h>
using namespace std;
 
class node
{
    public:
    int data;
    node* left;
    node* right;
     
    /* Constructor that allocates a new node
    with the given data and NULL left and right
    pointers. */
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
void increment(node* node, int diff)
{
    if(node->left != NULL)
    {
        node->left->data = node->left->data + diff;
     
        increment(node->left, diff);
    }
    else if (node->right != NULL) 
    {
        node->right->data = node->right->data + diff;
     
        increment(node->right, diff);
    }
}
void convertTree(node* node)
{
    int left_data = 0, right_data = 0, diff;
     
    if (node == NULL || (node->left == NULL &&
                        node->right == NULL))
        return;
    else
    {
        convertTree(node->left);
        convertTree(node->right);
     
        if (node->left != NULL)
        left_data = node->left->data;
     
        if (node->right != NULL)
        right_data = node->right->data;
     
        diff = left_data + right_data - node->data;
     
        if (diff > 0)
        node->data = node->data + diff;
     
        if (diff < 0)
        increment(node, -diff); 
    }
}
void printInorder(node* node)
{
    if (node == NULL)
        return;
     
    printInorder(node->left);
     
    std::cout<<node->data<<" ";
     
    printInorder(node->right);
}
int main()
{
    node *root = new node(50);
    root->left = new node(7);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(5);
    root->right->left = new node(1);
    root->right->right = new node(30);
     
    std::cout << "\nInorder traversal before conversion: " << std::endl;
    printInorder(root);
     
    convertTree(root);
     
    std::cout << "\nInorder traversal after conversion: " << std::endl;
    printInorder(root);
    return 0;
}