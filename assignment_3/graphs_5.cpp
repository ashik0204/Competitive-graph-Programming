class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=0;
        int i=0;
        int j;
        map <pair<int,int>,pair<int,int>>m;
        for(auto val:image){
            j=0;
            for(auto val1:val){
                m[{i,j}]={n,val1};
                j++;
                n++;
            }
            i++;
        }
        vector<int>vis(n);
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vis[m[{sr,sc}].first]=1;
        while(!q.empty()){
            pair<int,int>t=q.front();
            q.pop();
            vector<pair<int,int>> vts={{1,0},{0,1},{-1,0},{0,-1}};
            for(auto val:vts){
                int i1=val.first;
                int j1=val.second;
                if((t.first+i1>=0)&&(t.first+i1<i)&&(t.second+j1>=0)&&(t.second+j1<j)&&(!vis[m[{t.first+i1,t.second+j1}].first])){
                    if(m[t].second==m[{t.first+i1,t.second+j1}].second){
                        vis[m[{t.first+i1,t.second+j1}].first]=1;
                        q.push({t.first+i1,t.second+j1});
                    }
                }
            }
        }
        int i1=0;
        vector<vector<int>> vt;
        for(auto val:image){
            int j=0;
            vector<int> temp;
            for(auto val1:val){
                if(vis[m[{i1,j}].first]){
                    temp.push_back(color);
                }
                else{
                    temp.push_back(val1);
                }
                j++;
            }
            vt.push_back(temp);
            i1++;
        }
        return vt;
    }
};