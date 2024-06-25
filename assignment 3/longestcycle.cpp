class Solution{
private:
    int cycle(int src,vector<int>&ed,int vis[]){
        int n=ed.size();
        vis[src]=1;
        queue<int> q;
        q.push(src);
        int path_vis[n];
        
        fill(path_vis,path_vis+n,0);
        path_vis[src]=1;
        while(!q.empty()){
            int t=q.front();
            q.pop();
            int x=ed[t];
            if(x<0){
                vis[t]=1;
                continue;
            }
            if(!path_vis[x]){
                vis[x]=1;
                path_vis[x]=path_vis[t]+1;
                q.push(x);
            }
            else{
                return path_vis[t]-path_vis[x]+1;
            }
        }
        return -1;
    }
public:
    int longestCycle(vector<int> &ed){
        int n=ed.size();
        int max_len=-1;
        int vis[n];
        for(int i=0;i<n;i++){
            if(ed[i]<0){
                vis[i]=1;
            }
            else{
                vis[i]=0;
            }

        }
        int val;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                val=cycle(i,ed,vis);
                if(val>max_len){
                    max_len=val;
                }
            }
        }
        return max_len;
    }
};
