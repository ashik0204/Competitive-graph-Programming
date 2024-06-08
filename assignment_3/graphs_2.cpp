#include<bits/stdc++.h>
using namespace std;

int solve(int A, int **B, int n21, int n22) {
    vector<int> adj[n22+1];
    for(int i=0; i<n21; i++){
        adj[B[i][0]].push_back(B[i][1]);
    }
    queue <int> q;
    q.push(1);
    int vis[n22+1]={0};
    vis[1]=1;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        if(t==A) return 1;
        for(int i=0; i<adj[t].size(); i++){
            if(!vis[adj[t][i]]){
                vis[adj[t][i]]=1;
                q.push(adj[t][i]);
            }
        } 
    }
    return 0;
}

int main(){
    int A, c;
    cin >> A >> c;
    int** B = (int**)malloc(c*sizeof(int*));
    for(int i=0; i<c; i++){
        B[i] = (int*)malloc(2*sizeof(int));
        for(int j=0; j<2; j++){
            int m;
            cin >> m;
            B[i][j] = m;
        }
    }
    int n;
    cin >> n;
    cout << solve(A, B, c, n);
    for(int i=0; i<c; i++){
        free(B[i]);
    }
    free(B);
    
    return 0;
}
