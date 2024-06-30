vector<int> dijkstra(int start, const Graph& graph) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();
        
        if (currentDist > dist[currentNode]) continue;
        
        for (const auto& neighbor : graph[currentNode]) {
            int nextNode = neighbor.first;
            int weight = neighbor.second;
            if (dist[currentNode] + weight < dist[nextNode]) {
                dist[nextNode] = dist[currentNode] + weight;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }
    
    return dist;
}

int shortestPathWithExtraEdge(int A, const vector<vector<int>>& B, int C, int D, const vector<vector<int>>& E) {
    // Construct the graph
    Graph graph(A);
    for (const auto& edge : B) {
        int u = edge[0], v = edge[1], w = edge[2];
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
    
    // Get the shortest path distances from C and D
    vector<int> distFromC = dijkstra(C, graph);
    vector<int> distFromD = dijkstra(D, graph);
    
    // Find the shortest path from C to D without any extra edge
    int shortestPath = distFromC[D];
    
    // Check the shortest path considering one extra edge
    for (const auto& extraEdge : E) {
        int u = extraEdge[0], v = extraEdge[1], w = extraEdge[2];
        if (distFromC[u] != INT_MAX && distFromD[v] != INT_MAX) {
            shortestPath = min(shortestPath, distFromC[u] + w + distFromD[v]);
        }
        if (distFromC[v] != INT_MAX && distFromD[u] != INT_MAX) {
            shortestPath = min(shortestPath, distFromC[v] + w + distFromD[u]);
        }
    }
    
    return (shortestPath == INT_MAX) ? -1 : shortestPath;
}
