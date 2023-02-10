#include <iostream>
#include <vector>

struct Node {
    int value;
    std::vector<Node> children;
};

void findCheapestRec(
    Node* pNode,                    // current node
    int currSum,                    // current path sum
    std::vector<Node*>& currPath,   // the "global" path currently taken
    int& outMinSum,                 // the current minumum path sum
    std::vector<Node*>& outMinPath )// the current minumum path
{
    if ( !pNode )
        return;

    // First step: Calculate the current path and sum
    currSum += pNode->value;
    currPath.push_back( pNode );

    if ( pNode->children.empty() )
    {
        // Base: The node is a leaf
        if ( currSum < outMinSum )
        {
            outMinPath  = currPath;
            outMinSum   = currSum;
        }
    }
    else
    {
        // General case: Traverse the children
        for ( size_t i = 0; i < pNode->children.size(); i++ )
        {
            Node& child = pNode->children[ i ];

            findCheapestRec( &child, currSum, currPath, outMinSum, outMinPath );
        }
    }
    currPath.pop_back();
}

std::vector<Node*> findCheapestPath( Node* root )
{
    if ( !root )
        return {};

    std::vector<Node*>  currPath;
    std::vector<Node*>  minPath;
    int minSum = std::numeric_limits<int>::max();

    findCheapestRec( root, 0, currPath, minSum, minPath );

    return minPath;
}

int main()
{
    Node root = 
        Node { 5, {
                Node{ 8, {} },
                Node{ 0 , {} },
                Node{ 11, {} }
            } };


    std::vector<Node*> vec = findCheapestPath( &root );

    for ( size_t i = 0; i < vec.size(); i++ )
        std::cout << vec[ i ]->value << ' ';


	return 0;
}