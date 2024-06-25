#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector <int> adj[n];
    int indeg[n]={0};
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x<0){continue;}
        adj[x-1].push_back(i);
        indeg[i]++;
    }
    queue <int> q;
    int visited[n]={0};
    for(int i=0;i<n;i++){
        if(indeg[i]==0){
            q.push(i);
            visited[i]=1;
        }
    }
    int t;
    while(!q.empty()){
        t=q.front();
        q.pop();
        for(int x:adj[t]){
            if(--indeg[x]==0){
                q.push(x);
                visited[x]=visited[t]+1;
            }
        }
    }
    cout<<visited[t]<<endl;
    return 0;
}
