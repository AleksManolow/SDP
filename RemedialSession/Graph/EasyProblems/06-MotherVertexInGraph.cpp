#include<iostream>
#include<map>
#include<vector>
#include<queue>
void allPaths( std::vector<int> path)
{
    for(int v : path)
        std::cout << v << " ";

    std::cout << std::endl;
}
bool isReachable(int s, int d, std::map<int, std::vector<int>> adj)
{
    std::map<int, bool> visited;
    for (const auto& vertex : adj)
        visited[vertex.first] = false;

    std::queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int currentVertex = q.front();
        q.pop();

        if (currentVertex == d)
            return true;

        for (int neighbor : adj[currentVertex])
        {
            if (!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    
    return false;
}
std::vector<int> findMotherVertex(std::map<int, std::vector<int>> adj)
{
    std::vector<int> motherVertexs;  
    bool isMotherVertex = true;
    
    for (int i = 0; i < adj.size(); i++)
    {
        for (int j = 0; j < adj.size(); j++)
        {
            if (!isReachable(i, j, adj))
            {
                isMotherVertex = false;
            }
        }
        if (isMotherVertex)
        {
            motherVertexs.push_back(i);
        }
        isMotherVertex = true;
    }
    
    return motherVertexs;
}
int main()
{
    std::map<int, std::vector<int>> adj;
 
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].empty();
    adj[3].empty();
    adj[4].push_back(1);
    adj[5].push_back(6); 
    adj[5].push_back(2); 
    adj[6].push_back(4); 
    adj[6].push_back(0); 

    std::vector<int> motherVertexs = findMotherVertex(adj);

    for (int v : motherVertexs)
    {
        std::cout << v << " ";
    }
    
    return 0;
}