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
int main()
{
    Node* root = new Node(10);
    root->children.push_back(new Node(3));
    root->children.push_back(new Node(7));
    root->children.push_back(new Node(12));
    root->children[0]->children.push_back(new Node(5));
    root->children[0]->children.push_back(new Node(8));
    root->children[0]->children.push_back(new Node(9));
    root->children[0]->children[1]->children.push_back(new Node(1));
    root->children[0]->children[1]->children.push_back(new Node(2));
    root->children[1]->children.push_back(new Node(11));
    root->children[1]->children.push_back(new Node(13));
    root->children[2]->children.push_back(new Node(6));
    root->children[2]->children.push_back(new Node(4));

    print(root);

    deleteTree(root);

    return 0;
}