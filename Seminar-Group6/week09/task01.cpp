#include<iostream>
struct Node
{
    int key;
    Node* left;
    Node* right;

    Node(int _key):key(_key), left(nullptr), right(nullptr){}
};
bool isBSTRec(Node* t, int min, int max) {
	if (t == nullptr)
		return true;

	if (t->key < min || t->key > max)
		return false;

	return isBSTRec(t->left, min, t->key) && isBSTRec(t->right, t->key, max);
}

bool isBST(Node* t) {
	return isBSTRec(t, INT_MIN, INT_MAX);
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
    
    std::cout << isBST(test) << std::endl;
    test->left->right = new Node(20);
    std::cout << isBST(test) << std::endl;

    clean(test);    

    return 0;
}