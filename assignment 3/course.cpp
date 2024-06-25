class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& reqs) {
        vector<int> adj[n];
        int indeg[n];
        for(int i=0;i<n;i++){
            indeg[i]=0;
        }
        for(int i=0;i<reqs.size();i++){
            adj[reqs[i][1]].push_back(reqs[i][0]);
            indeg[reqs[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        vector<int> res;
        while(!q.empty()){
            int t=q.front();
            q.pop();
            res.push_back(t);
            for(int x:adj[t]){
                if(--indeg[x]==0){
                    q.push(x);
                }
            }
        }
        if(res.size()!=n){
            res.clear();
            return res;
        }
        return res;
    }
};
