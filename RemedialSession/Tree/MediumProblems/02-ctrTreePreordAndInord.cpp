#include<iostream>
#include<vector>
struct Node
{
    char key;
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
int search(char arr[], int strt, int end, char value)
{
    for (int i = strt; i < end; i++)
    {
        if (arr[i] == value)
            return i;
    }
}
Node* buildTree(char in[], char pre[], int inStrt, int inEnd)
{
    static int preIndex = 0;

    if (inStrt > inEnd)
        return nullptr;

    Node* node = new Node(pre[preIndex++]);
    
    if (inStrt == inEnd)
        return node;
    
    int index = search(in, inStrt, inEnd, node->key);

    node->left = buildTree(in, pre, inStrt, index - 1);
    node->right = buildTree(in, pre, index + 1, inEnd);

    return node;
}
void printInorder(Node* node)
{
    if (node == NULL)
        return;

    printInorder(node->left);

    std::cout<<node->key<<" ";

    printInorder(node->right);
}
int main()
{
    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
    int len = sizeof(in) / sizeof(in[0]);
    Node* root = buildTree(in, pre, 0, len - 1);
    
    printInorder(root);

    clean(root);
}