#include<iostream>
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
bool identicalTree(Node* t1, Node* t2)
{
    if (t1 == nullptr && t2 == nullptr)
    {
        return true;
    }

    if ((t1 == nullptr && t2 != nullptr)
        || (t1 != nullptr && t2 == nullptr)
        || (t1->key != t2->key))
    {
        return false;
    }

    return identicalTree(t1->left, t2->left) && identicalTree(t1->right, t2->right);
}
int main()
{
    Node* t1 = new Node(22);
    t1->left = new Node(12);
    t1->right = new Node(30);
    t1->left->left = new Node(8);
    t1->left->right = new Node(20);

    Node* t2 = new Node(22);
    t2->left = new Node(12);
    t2->right = new Node(30);
    t2->left->left = new Node(8);
    t2->left->right = new Node(20);

    std::cout << identicalTree(t1, t2) << std::endl;

    clean(t1);
    clean(t2);
}