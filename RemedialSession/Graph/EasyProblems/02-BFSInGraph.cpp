#include<iostream>
#include<map>
#include<vector>
#include<queue>
void BFS(int v, std::map<int, bool> visited, std::map<int, std::vector<int>> adj)
{
    std::queue<int> q;
    q.push(v);
    visited[v] = true;

    while (!q.empty())
    {
        int currentVertex = q.front();
        q.pop();
        std::cout << currentVertex << " ";

        for(int neighbor : adj[currentVertex])
        {
            if (!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}
int main()
{
    std::map<int, std::vector<int>> adj;
    std::map<int, bool> visited;
    for (const auto& vertex : adj)
        visited[vertex.first] = false;

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[3].push_back(5);

    BFS(0,visited, adj);

    return 0;
}