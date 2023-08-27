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
int main()
{
    std::map<int, std::vector<int>> adj;
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);
    adj[1].push_back(3);
    adj[2].push_back(0);    
    adj[2].push_back(1);

    int u = 0, v = 3;//13
    if(isReachable(u, v, adj))
        std::cout<< "There is a path from " << u << " to " << v << std::endl;
    else
        std::cout<< "There is no path from " << u << " to " << v << std::endl;
 
    u = 3, v = 0;
    if(isReachable(u, v, adj))
        std::cout<< "There is a path from " << u << " to " << v << std::endl;
    else
        std::cout<< "There is no path from " << u << " to " << v << std::endl;

    return 0;
}