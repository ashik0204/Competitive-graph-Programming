class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    
    // Initialize the distance matrix
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }
    
    for (const auto& edge : edges) {
        int from = edge[0];
        int to = edge[1];
        int weight = edge[2];
        dist[from][to] = weight;
        dist[to][from] = weight;
    }
    
    // Floyd-Warshall Algorithm
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    // Find the city with the smallest number of reachable cities within the distance threshold
    int minReachableCities = INT_MAX;
    int bestCity = -1;
    
    for (int i = 0; i < n; ++i) {
        int reachableCities = 0;
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] <= distanceThreshold) {
                ++reachableCities;
            }
        }
        
        // Prefer the city with a greater number in case of tie
        if (reachableCities < minReachableCities || (reachableCities == minReachableCities && i > bestCity)) {
            minReachableCities = reachableCities;
            bestCity = i;
        }
    }
    
    return bestCity;
}
};
