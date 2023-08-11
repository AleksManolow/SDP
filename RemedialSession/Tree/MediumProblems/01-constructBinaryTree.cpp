#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left, *right;
};
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
void printInorder(Node* node)
{
    if (node == NULL)
        return;
 
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}
Node* constructBinaryTreeUtil(int pre[], int preM[],
                    int &preIndex, int l,int h,int size)
{   
    // Base case
    if (preIndex >= size || l > h)
        return NULL;
 

    Node* root = newNode(pre[preIndex]);
        ++(preIndex);
 
    if (l == h)
        return root;
     
    int i;
    for (i = l; i <= h; ++i)
        if (pre[preIndex] == preM[i])
            break;
 
    if (i <= h)
    {
        root->left = constructBinaryTreeUtil (pre, preM,
                                    preIndex, i, h, size);
        root->right = constructBinaryTreeUtil (pre, preM,
                                 preIndex, l+1, i-1, size);
    }

    return root;   
}
void constructBinaryTree(Node* root,int pre[],
                        int preMirror[], int size)
{
    int preIndex = 0;
    int preMIndex = 0;
 
    root =  constructBinaryTreeUtil(pre,preMirror,
                            preIndex,0,size-1,size);
 
    printInorder(root);
}
int main()
{
    int preOrder[] = {1,2,4,5,3,6,7};
    int preOrderMirror[] = {1,3,7,6,2,5,4};
 
    int size = sizeof(preOrder)/sizeof(preOrder[0]);
 
    Node* root = new Node;
 
    constructBinaryTree(root,preOrder,preOrderMirror,size);
 
    return 0;
}