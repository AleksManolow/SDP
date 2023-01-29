#include<iostream>
#include<vector>
struct Node
{
    int data;
    std::vector<Node*> children;

    Node(int _data) : data(_data) { }
};
void deleteTree(Node* root)
{
	if ( root )
	{
		for ( Node* child : root->children)
		{
			deleteTree( child );
		}
		delete root;
	}
}
void print(Node* root)
{
    if (!root)
        return;
    
    std::cout << root->data << ' ';
    for (size_t i = 0; i < root->children.size(); i++)
    {
        print(root->children[i]);
    }
}
bool isEvenAdsDifference(Node* root)
{
    for (auto child : root->children)
    {
        if (abs(child->data - root->data) % 2 == 1)
            return false;
    }
    return true;
}
bool isGraceful(Node* root)
{
    if (root->children.size() == 0)
        return true;
    
    if (isEvenAdsDifference(root))
    {
        bool isTrue = 1;
        for (size_t i = 0; i < root->children.size(); i++)
        {
            isTrue = isTrue && isGraceful(root->children[i]);
        }
        return isTrue;
    }
    return false;
}
int main()
{
    Node* rootOne = new Node(1);
    rootOne->children.push_back(new Node(3));
    rootOne->children.push_back(new Node(5));
    rootOne->children.push_back(new Node(7));
    rootOne->children.push_back(new Node(9));

    Node* rootTwo = new Node(7);
    rootTwo->children.push_back(new Node(3));
    rootTwo->children[0]->children.push_back(new Node(9));
    rootTwo->children[0]->children[0]->children.push_back(new Node(5));
    rootTwo->children[0]->children[0]->children.push_back(new Node(1));

    Node* rootThree = new Node(1);
    rootThree->children.push_back(new Node(3));
    rootThree->children.push_back(new Node(5));
    rootThree->children.push_back(new Node(7));
    rootThree->children.push_back(new Node(9));
    rootThree->children[1]->children.push_back(new Node(42));

    std::cout << isGraceful(rootOne) << std::endl;
    std::cout << isGraceful(rootTwo) << std::endl;
    std::cout << isGraceful(rootThree) << std::endl;

    deleteTree(rootOne);
    deleteTree(rootTwo);
    deleteTree(rootThree);

    return 0;
}