#include<iostream>
struct Node
{
    int key;
    Node* left;
    Node* right;

    Node(int _key, Node* _left = nullptr, Node* _right = nullptr):key(_key), left(_left), right(_right){}
};
bool areEqualTree(const Node* firstTree, const Node* secondTree)
{
    if (!firstTree && !secondTree)
        return true;
    if (firstTree->key != secondTree->key)
        return false;
    
    return areEqualTree(firstTree->left, secondTree->left) && areEqualTree(firstTree->right, secondTree->right);
}
void clean(Node*& n) {
    if (n == nullptr) return;
    clean(n->left);
    clean(n->right);
    delete n;
}
int main()
{
    Node* firstTree = new Node(100);
    firstTree->left = new Node(50);
    firstTree->right = new Node(140);
    firstTree->left->left = new Node(25);

    Node* secoundTree = new Node(100);
    secoundTree->left = new Node(50);
    secoundTree->right = new Node(140);
    secoundTree->left->left = new Node(25);

    std::cout << areEqualTree(firstTree, secoundTree) << std::endl;

    Node* thirdTree = new Node(100);
    thirdTree->left = new Node(50);
    thirdTree->right = new Node(10);
    thirdTree->left->left = new Node(25);

    std::cout << areEqualTree(firstTree, thirdTree) << std::endl;

    return 0;
}