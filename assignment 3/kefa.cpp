#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
ll DFS(int src, vector<int> adj[], int visited[], int a[], int m, int sum) {
    visited[src] = 1;
    ll val = 0;
 
    if (a[src]) {
        sum += 1;
    } else {
        sum = 0;
    }
 
    if (sum > m) {
        return 0;
    }
    if(adj[src].size()==0){
        if(sum<=m){
            val+=1;
        }
        return val;
    }
    for (int x : adj[src]) {
        if (!visited[x]){
         val += DFS(x, adj, visited, a, m, sum);
        }
    }
 
    return val;
}
 
int main() {
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> adj[n];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v; // Read the values of u and v
        adj[u - 1].push_back(v - 1);
    }
    int visited[n] = {0};
    cout << DFS(0, adj, visited, a, m, 0) << endl;
}
