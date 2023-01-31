#include<iostream>
struct Node
{
    char data;
    Node *left;
    Node *right;

    Node(char _data, Node* _left = nullptr, Node* _right = nullptr) : data(_data), left(_left), right(_right) {}
};
void clear(Node* tree)
{
    if (!tree)
        return;
    clear(tree->left);
    clear(tree->right);
    delete tree;
}
bool helper(Node* tree, char* word)
{   
    //std::cout << tree->data << "--" << *word << std::endl;
    if (*word == '\0')
        return true;
        
    if (!tree || tree->data != *word)
        return false;
    
    return tree->data == *word && (helper(tree->right, (word + 1)) || helper(tree->left, (word + 1)));
}
bool containsWord(Node* tree, char* word)
{
    if (!tree)
        return false;
    if(tree->data == *word) 
        return helper(tree, word);
    return containsWord(tree->left, word) || containsWord(tree->right, word);
}
int main()
{
    Node* tree = new Node('a');
    tree->left = new Node('c');
    tree->right = new Node('b');
    tree->left->left = new Node('f');
    tree->left->right = new Node('d');
    tree->right->right = new Node('e');
    
    char* word1 = new char[3];
    word1[0] = 'a';
    word1[1] = 'f';
    word1[2] = '\0';

    char* word2 = new char[4];
    word2[0] = 'a';
    word2[1] = 'c';
    word2[2] = 'd';
    word2[3] = '\0';

    std::cout << containsWord(tree, word1) << std::endl;
    std::cout << containsWord(tree, word2) << std::endl;

    return 0;
}