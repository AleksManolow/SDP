#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include <limits>
std::vector<int> dijkstra(int source, std::map<int, std::vector<std::pair<int, int>>> adjacencyList)
{
    std::vector<int> dist(adjacencyList.size(), INT_MAX); // Инициализираме всички разстояния с безкрайност
    dist[source] = 0; // Началният връх има разстояние 0

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq; // Min-heap за най-малките разстояния
    pq.push({0, source}); // Първо вкарваме началния връх с разстояние 0

    while (!pq.empty()) {
        int u = pq.top().second; // Извличаме връх
        int uDist = pq.top().first; // Извличаме разстоянието до него
        pq.pop();

        if (uDist > dist[u]) {
            continue; // Пропускаме връх, ако имаме по-добро разстояние до него
        }

        for (const auto& neighbor : adjacencyList[u]) {
            int v = neighbor.first; // Съседният връх
            int weight = neighbor.second; // Тегло на реброто

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight; // Обновяваме най-краткото разстояние до съседния връх
                pq.push({dist[v], v}); // Добавяме съседа в опашката
            }
        }
    }

    return dist;
}
int main()
{
    std::map<int, std::vector<std::pair<int, int>>> adj;
 
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 1});
    adj[3].push_back({5, 5});
    adj[4].push_back({5, 2});
    adj[5].empty();

    int source = 0;
    std::vector<int> shortestDistances = dijkstra(source, adj);

    std::cout << "Shortest distances from vertex " << source << " to all other vertices:" << std::endl;
    for (int i = 0; i < shortestDistances.size(); ++i) {
        std::cout << "Vertex " << i << ": " << shortestDistances[i] << std::endl;
    }

    return 0;
}
// Output(Shortest distances from vertex 0 to all other vertices):
// Vertex 0: 0
// Vertex 1: 2
// Vertex 2: 3
// Vertex 3: 9
// Vertex 4: 6
// Vertex 5: 8