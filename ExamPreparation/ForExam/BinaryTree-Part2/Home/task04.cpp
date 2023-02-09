#include<iostream>
#include<vector>
#include<algorithm>
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
void onlyNodes(Node* tree, std::vector<int>& nodes)
{
    if (!tree)
        return;
    
    nodes.push_back(tree->data);
    onlyNodes(tree->left, nodes);
    onlyNodes(tree->right, nodes);
}
bool leavesAreEqual(Node* bt1, Node* bt2)
{
    std::vector<int> nodesbt1;
    std::vector<int> nodesbt2;

    onlyNodes(bt1, nodesbt1);
    onlyNodes(bt2, nodesbt2);

    if (nodesbt1.size() != nodesbt2.size())
        return false;
    
    sort(nodesbt1.begin(), nodesbt1.end());
    sort(nodesbt2.begin(), nodesbt2.end());

    for (size_t i = 0; i < nodesbt1.size(); i++)
    {
        if (nodesbt1[i] != nodesbt2[i])
            return false;
    }
    return true;
}
int main()
{
    Node* bt1 = new Node(10);
    bt1->left = new Node(1);
    bt1->right = new Node(25);
    bt1->right->right = new Node(30);
    bt1->right->right->left = new Node(26);
    bt1->right->right->right = new Node(32);

    Node* bt2 = new Node(25);
    bt2->left = new Node(10);
    bt2->left->left = new Node(1);
    bt2->right = new Node(30);
    bt2->right->left = new Node(32);
    bt2->right->right = new Node(26);

    Node* bt4 = new Node(10);
    bt4->left = new Node(1);
    bt4->right = new Node(25);
    bt4->right->right = new Node(30);
    bt4->right->right->left = new Node(27);
    bt4->right->right->right = new Node(32);

    std::cout << leavesAreEqual(bt1, bt2) << std::endl;
    std::cout << leavesAreEqual(bt1, bt4) << std::endl;

    clear(bt1);
    clear(bt2);
    return 0;
}