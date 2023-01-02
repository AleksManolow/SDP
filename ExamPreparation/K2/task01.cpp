// Да се напише функция, която намира сумата на всички елементи на двоично наредено дърво от цели числа,
// които имат нечетен брой наследници в интервала [x, y] (т.е. сумата на броя елементи в лявото поддърво
// и броя елементи в дясното поддърво в интервала [x, y] е нечетно число). Нека x и y са параметри на функцията.
#include<iostream>
struct Node
{
    int key;
    Node* left;
    Node* right;

    Node(int _key, Node* _left = nullptr, Node* _right = nullptr):key(_key), left(_left), right(_right){}
};
int numberOfNodes(Node* tree)
{
    if (!tree)
    {
        return 0;
    }
    return 1 + numberOfNodes(tree->left) + numberOfNodes(tree->right);
}
int sumEl(Node* tree, int x, int y)
{
    if (!tree)
        return 0;
    
    int numberOfHeirs = numberOfNodes(tree) - 1;
    if (numberOfHeirs % 2 != 0 && numberOfHeirs >= x && numberOfHeirs <= y)
        return tree->key + sumEl(tree->left, x, y) + sumEl(tree->right, x, y);

    return sumEl(tree->left, x, y) + sumEl(tree->right, x, y);
}
void clean(Node*& n) {
    if (n == nullptr) return;
    clean(n->left);
    clean(n->right);
    delete n;
}
int main()
{
    Node* tree = new Node(5);
    tree->left = new Node(3);
    tree->left->left = new Node(1);
    tree->left->right = new Node(4); 
    tree->right = new Node(9);
    tree->right->left = new Node(6);
    tree->right->right = new Node(11); 
    tree->right->left->right = new Node(7);
    tree->right->right->right = new Node(10); 
    tree->right->right->left = new Node(12); 
    
    std::cout << sumEl(tree ,2 , 9) << std::endl;
    
    clean(tree);

    return 0;
}