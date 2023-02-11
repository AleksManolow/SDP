#include<iostream>
#include<vector>
struct Node
{
    int value;
    std::vector<Node*> children;
};
void clean(Node* root)
{
    if (!root)
        return;
    for (size_t i = 0; i < root->children.size(); i++)
    {
        clean(root->children[i]);
    }
    delete root;
}
void findCheapestRec(Node* root, int currSum, int& minSum)
{
    currSum += root->value;

    if (root->children.empty())
    {
        if (currSum < minSum)
        {
            minSum = currSum;
        }   
    }
    else
    {
        for (int i = 0; i < root->children.size(); i++)
        {
            findCheapestRec(root->children[i], currSum, minSum);
        }
    }
    
}
int findCheapestsSum(Node* root)
{
    int minSum = INT_MAX;
    findCheapestRec(root, 0, minSum);
    return minSum;
}
int main()
{
    Node* root = new Node();
    root->value = 5;
    root->children.push_back(new Node());
    root->children[0]->value = 4;
    root->children.push_back(new Node());
    root->children[1]->value = 2;
    root->children.push_back(new Node());
    root->children[2]->value = 8;

    std::cout << findCheapestsSum(root) << std::endl;

    clean(root);
    
    return 0;
}