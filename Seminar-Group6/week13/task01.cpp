#include<vector>
#include<queue>
#include<iostream>

bool hasCycleRec(const std::vector<std::vector<int>>& graph, int start, std::vector<bool>& visited) {
    visited[start] = true;

    for (const auto& vertex : graph[start]) {
        if (visited[vertex])
            return true;

        if (hasCycleRec(graph, vertex, visited))
            return true;
    }

    visited[start] = false;

    return false;
}

bool hasCycle(const std::vector<std::vector<int>>& graph) {
    std::vector<bool> visited(graph.size(), false);

    for (int i = 0; i < graph.size(); i++) {
        if (!visited[i] && hasCycleRec(graph, i, visited)) {
            return true;
        }
    }

    return false;
}
bool canFinish(int numCourses, std::vector<std::pair<int, int>>& prerequisites) {
    std::vector<std::vector<int>> graph(numCourses);

    for (const auto& edgePair : prerequisites)
        graph[edgePair.first].push_back(edgePair.second);

    std::vector<int> inDegree(numCourses, 0);

    for(int i = 0; i < numCourses; i++) {
        for(const auto& vertex : graph[i]) {
            inDegree[vertex]++;
        }
    }

    std::queue<int> q;


    for(int i = 0; i < numCourses; i++) {
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }


    while(!q.empty()) {
        int currentNode = q.front();
        q.pop();

        for(const auto& n : graph[currentNode]) {
            inDegree[n]--;

            if(inDegree[n] == 0)    
                q.push(n);
        }
    }

    for(const auto& n : inDegree) {
        if(n != 0)
            return false;
    }

    return true;
}

int main() {
    
}