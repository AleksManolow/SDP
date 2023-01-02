#include<iostream>
struct Node
{
    int key;
    Node* left;
    Node* right;

    Node(int _key, Node* _left = nullptr, Node* _right = nullptr):key(_key), left(_left), right(_right){}
};
void rotateLeft(Node*& root) {
	Node* originalRight = root->right;
	root->right = originalRight->left;
	originalRight->left = root;
	root = originalRight;
}
void rotateRight(Node*& root) {
	Node* originalLeft = root->left;
	root->left = originalLeft->right;
	originalLeft->right = root;
	root = originalLeft;
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

    rotateRight(firstTree);
    std::cout << (firstTree->key == 50) << std::endl;
    rotateLeft(firstTree);
    std::cout << (firstTree->key == 100) << std::endl; 

    clean(firstTree);
    return 0;
}