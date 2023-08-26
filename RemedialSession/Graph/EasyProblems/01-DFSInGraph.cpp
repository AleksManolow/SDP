#include<iostream>
#include<map>
#include<vector>
#include<stack>
void DFSrec(int v, std::map<int, bool> visited, std::map<int, std::vector<int>> adj)
{
    visited[v] = true;
    std::cout << v << " ";

    for (int neighbor : adj[v])
    {
        if (!visited[neighbor])
        {
            DFSrec(neighbor, visited, adj);
        }
    }
}
void DFSstack(int v, std::map<int, bool> visited, std::map<int, std::vector<int>> adj)
{
    std::stack<int> s;
        s.push(v);

    while (!s.empty())
    {
        int currentVertex = s.top();
        s.pop();

        if (!visited[currentVertex])
        {
            std::cout << currentVertex << " ";
            visited[currentVertex] = true;
        }

        for (int neighbor : adj[currentVertex])
        {
            if (!visited[neighbor])
            {
                s.push(neighbor);
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

    DFSrec(0,visited, adj);

    std::cout << std::endl;

    DFSstack(0,visited, adj);

    return 0;
}