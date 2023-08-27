#include<iostream>
#include<map>
#include<vector>
void allPaths( std::vector<int> path)
{
    for(int v : path)
        std::cout << v << " ";

    std::cout << std::endl;
}
// Approach:
//   1.The idea is to do Depth First Traversal of a given directed graph.
//   2.Start the DFS traversal from the source.
//   3.Keep storing the visited vertices in an array or HashMap say ‘path[]’.
//   4.If the destination vertex is reached, print the contents of path[].
//   5.The important thing is to mark current vertices in the path[] as visited also so that the traversal doesn’t go in a cycle.
void printPath(int s, int d,std::map<int, bool> visited, std::map<int, std::vector<int>> adj, std::vector<int> path)
{
    visited[s] = true;
    path.push_back(s);

    if (s == d)
    {
        allPaths(path);
        return;
    }
    
    for (int neighbor : adj[s])
    {
        if (!visited[neighbor])
        {
            printPath(neighbor, d ,visited, adj, path);
        }
    }
}
int main()
{
    std::map<int, std::vector<int>> adj;
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);
    adj[1].push_back(3);
    adj[2].push_back(0);    
    adj[2].push_back(1);

    std::map<int, bool> visited;
    for (const auto& vertex : adj)
        visited[vertex.first] = false;

    std::vector<int> path;

    int s = 2;
    int d = 3;

    printPath(s,d,visited, adj, path);

    return 0;
}