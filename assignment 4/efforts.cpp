class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
    int rows = heights.size();
    int cols = heights[0].size();
    
    vector<vector<int>> effort(rows, vector<int>(cols, INT_MAX));
    effort[0][0] = 0;
    
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({0, 0, 0});
    
    vector<int> dirX = {-1, 1, 0, 0};
    vector<int> dirY = {0, 0, -1, 1};
    
    while (!pq.empty()) {
        auto [currentEffort, x, y] = pq.top();
        pq.pop();
        
        if (x == rows - 1 && y == cols - 1) {
            return currentEffort;
        }
        
        for (int i = 0; i < 4; ++i) {
            int newX = x + dirX[i];
            int newY = y + dirY[i];
            
            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
                int nextEffort = max(currentEffort, abs(heights[newX][newY] - heights[x][y]));
                
                if (nextEffort < effort[newX][newY]) {
                    effort[newX][newY] = nextEffort;
                    pq.push({nextEffort, newX, newY});
                }
            }
        }
    }
    
    return 0;
}A
};
