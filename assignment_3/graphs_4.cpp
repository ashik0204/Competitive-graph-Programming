class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector <int> vis(n);
        vector <int> adj[n];
        for(auto val: edges){
            adj[val[0]].push_back(val[1]);
            adj[val[1]].push_back(val[0]);
        }
        queue<int> q;
        q.push(source);
        vis[source]=1;
        while(!q.empty()){
            int t=q.front();
            q.pop();
            if(t==destination){
                return true;
            }
            for(int i=0;i<adj[t].size();i++){
                if(!vis[adj[t][i]]){
                    q.push(adj[t][i]);
                    vis[adj[t][i]]=1;
                }
            }
        }
        return false;
    }
};