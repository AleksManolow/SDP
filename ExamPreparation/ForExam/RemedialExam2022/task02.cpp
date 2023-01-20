#include<iostream>
struct Node
{
    int data;
    Node* left;
    Node* right;
};
//A)
Node* toTree(const int* sorted_data, size_t size)
{
    if (size  == 0)
    {
        return nullptr;
    }
    int mid;
    Node* newTreeNode = new Node();
    if(size % 2 == 0)
    {
        mid = size / 2 - 1;
        newTreeNode->data = sorted_data[mid];
        newTreeNode->left = toTree(sorted_data, mid);
        newTreeNode->right = toTree((sorted_data + mid + 1), mid + 1);
    }  
    else
    {
        mid = size / 2;
        newTreeNode->data = sorted_data[mid];
        newTreeNode->left = toTree(sorted_data, mid);
        newTreeNode->right = toTree((sorted_data + mid + 1), mid);
    }
    return newTreeNode;
}
//B)
void release(Node*& n) {
    if (n == nullptr) return;
    release(n->left);
    release(n->right);
    delete n;
}
//C)
// size_t toArray(Node* tree, int* output)
// {
//     if (tree == nullptr)
//     {
//         return 0;
//     }
//     toArray(tree->left, (++output));
//     *(output) = tree->data;
//     toArray(tree->right, (++output));
// }
void print(Node* n)
{
    if (n == nullptr)
    {
        return;
    }
    std::cout << n->data << " ";
    print(n->left);
    print(n->right);
}
int main()
{
    int* array = new int[6];
    for (size_t i = 0; i < 6; i++)
    {
        array[i] = i + 1;
    }
    Node* test = toTree(array, 6);
    
    print(test);

    release(test); 
    delete array;
    return 0;
}
