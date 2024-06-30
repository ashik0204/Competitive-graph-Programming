#include <bits/stdc++.h>
using namespace std;
#define ll long long    
int main(){
    int V,E;
    cin>>V>>E;
    vector<pair<int,int>> adj[V+1];
    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    int src=1;
    int dist[V+1];
    fill(dist,dist+V+1,INT_MAX);
    dist[src]=0;
    pq.push({0,src});
    int visited[V+1]={0};
    int predecessor[V+1]={0};
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        visited[u]=1;
        
        for(auto it:adj[u]){
            int v=it.first;
            int w=it.second;
            if(!visited[v] && dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                predecessor[v]=u;
                pq.push({dist[v],v});
            }
        }
    }
    if(predecessor[V]==0){
        cout<<"-1"<<endl;
    }
    else{
        vector<int>path;
        int v=V;
        while(v!=0){
            path.push_back(v);
            v=predecessor[v];
        }
        reverse(path.begin(),path.end());
        for(int i=0;i<path.size();i++){
            cout<<path[i]<<" ";
        }
        cout<<endl;
    }
}
