#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter rows in snake matrix ";
    cin>>n;
    cout<<"matrix"<<endl;
    map<int,int> mp;
    for(int i=1;i<101;i++){
        mp[i]=0;
    }
    for(int i=0;i<n;i++){
        int mouth,tail;
        cin>>mouth>>tail;
        mp[mouth]=tail;
    }
    cout<<"enter rows in snake matrix ";
    cin>>n;
    cout<<"matrix"<<endl;
    
    for(int i=0;i<n;i++){
        int foot,top;
        cin>>foot>>top;
        mp[foot]=top;
    }
    queue <pair<int,int>> qu_1;
    qu_1.push({1,0});
    while(!qu_1.empty()){
        pair<int,int> curr_pos=qu_1.front();
        qu_1.pop();
        int pos=curr_pos.first;
        int step=curr_pos.second;
        if(pos==100){
            cout<<step<<endl;
            break;
        }
        for(int i=pos+1;i<pos+7&&i<=100;i++){
            if(mp[i]){
                curr_pos={mp[i],step+1};
                qu_1.push(curr_pos);
            }
            else{
                curr_pos={i,step+1};
                qu_1.push(curr_pos);
            }

        }
    }
    return 0;
}