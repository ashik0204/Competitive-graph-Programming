class Solution {
private:
    bool checkBipartite(vector<vector<int>>& graph, int val_, vector<int>& vis) {
        int n = graph.size();
        queue<int> q;
        q.push(val_);
        vis[val_] = 1;

        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (auto val : graph[t]) {
                if (vis[val] == 0) {
                    vis[val] = -vis[t];
                    q.push(val);
                } else if (vis[val] == vis[t]) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        
        for (int i = 0; i < n; ++i) {
            if (vis[i] == 0) {
                if (!checkBipartite(graph, i, vis)) {
                    return false;
                }
            }
        }
        return true;
    }
};
