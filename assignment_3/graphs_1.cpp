#include <bits/stdc++.h>
using namespace std;
class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    int vis[V]={0};
        queue <int> q;
        q.push(0);
        int level=0;
        vis[0]=1;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int t=q.front();
                q.pop();
                if(t==X) return level;
                for(int i=0;i<adj[t].size();i++){
                    if(!vis[adj[t][i]]){
                        vis[adj[t][i]]=1;
                        q.push(adj[t][i]);
                    }
                }
            }
            level+=1;
        }
        return -1;
	}
};