class Solution {
  private:
    void DFS(int ap[],int parent[],int HighPt[],vector<int> adj[],int &dfn,int visited[],int src,int DFN[]){
        DFN[src]=dfn++;
        visited[src]=1;
        int children=0;
        for(int x:adj[src]){
            if(!visited[x]){
                children++;
                parent[x]=src;
                DFS(ap,parent,HighPt,adj,dfn,visited,x,DFN);
                HighPt[src]=min(HighPt[src],HighPt[x]);
                if(HighPt[x]>=DFN[src]&&parent[src]!=-1) ap[src]=1;
                if (parent[src] == -1 && children > 1) {
                    ap[src] = 1;
                }
            }
            else if(parent[src]!=x){
                HighPt[src]=min(DFN[x],HighPt[src]);
            }
        }
        
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        int ap[V]={0};
        int parent[V];
        int HighPt[V];
        int DFN[V];
        int visited[V]={0};
        for(int i=0;i<V;i++){
            HighPt[i]=INT_MAX;
        }
        parent[0]=-1;
        int dfn=1;
        DFS(ap,parent,HighPt,adj,dfn,visited,0,DFN);
        vector<int> v;
        for(int i=0;i<V;i++){
            if(ap[i]){
                v.push_back(i);
            }
        }
        if(v.size()==0){
            v.push_back(-1);
        }
        return v;
    }
};
