#include<iostream>
#include<vector>
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int _data, Node* _left = nullptr, Node* _right = nullptr) : data(_data), left(_left), right(_right) { }
};
void clear(Node* tree)
{
    if (!tree)
        return;
    clear(tree->left);
    clear(tree->right);
    delete tree;
}
int sumTree(Node* tree)
{
    if (!tree)
        return 0;
    return tree->data + sumTree(tree->left) + sumTree(tree->right);
}
void onlyNodes(Node* tree, std::vector<int>& nodes)
{
    if (!tree)
        return;
    
    onlyNodes(tree->right, nodes);
    nodes.push_back(tree->data);
    onlyNodes(tree->left, nodes);
}
void buildFromRec(Node* tree, const std::vector<int> v, int id)
{
    if (!tree)
        return;
    buildFromRec(tree->right, v, id);
    tree->data = v[id++];
    buildFromRec(tree->left, v, id);
}
void convert(Node*& tree)
{
    std::vector<int> newNodes;
    onlyNodes(tree, newNodes);
    for (int i = 1; i < newNodes.size(); i++)
    {
        newNodes[i] += newNodes[i - 1];
    }
    buildFromRec(tree, newNodes, 0);
}
void print(Node* tree)
{
    if (!tree)
        return;
    print(tree->right);
    std::cout << tree->data << ' '; 
    print(tree->left);
    
}
int main()
{
    Node* tree = new Node(4);
    tree->left = new Node(1);
    tree->right = new Node(6);
    tree->left->left = new Node(0);
    tree->left->right = new Node(2);
    tree->left->right->right = new Node(3);
    tree->right->left = new Node(5);
    tree->right->right = new Node(7);
    tree->right->right->right = new Node(8);

    
    convert(tree);
    
    print(tree);

    clear(tree);
    return 0;
}