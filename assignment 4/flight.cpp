class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> m;
        for(auto flight : flights){
            m[flight[0]].push_back({flight[1], flight[2]});
        }
        
        vector<vector<int>> dp(n, vector<int>(k+2, INT_MAX));
              
        dp[src][0] = 0;
        
        for(int j=0; j<=k; j++){
            for(int i=0; i<n; i++){
                if(dp[i][j] == INT_MAX)
                    continue;
                
                auto &v = m[i];
                for(int index = 0; index<v.size(); index++){
                    int city_next = v[index].first;
                    int price_next = v[index].second;
                    
                    dp[city_next][j+1] = min(dp[city_next][j+1], dp[i][j] + price_next);
                }
            }
        }
        
        int min_price = INT_MAX;
        for(int i=0; i<=k+1; i++){
            min_price = min(min_price, dp[dst][i]);
        }
        return min_price==INT_MAX?-1:min_price;
    }
};
