#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int n,k;
    while(t--){
        cin>>n>>k;
        if(n<k){
            cout<<ceil(k/n);
        }
        else{
            int count=1;
            while(n>=k){
                k*=count;
                count++;
            }
            cout<<ceil(k/n);
        }
    }
    return 0;
}
  
