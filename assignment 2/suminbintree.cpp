#include <bits/stdc++.h>
using namespace std;
int func(int n){
    if(n==1){
        return 1;
    }
    if(n%2){
        return (n+func((n-1)/2));
    }
    else{
        return (n+func(n/2));
    }
}
int main(){
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        cin>>n;
        cout<<func(n)<<endl;
    }
    return 0;
}
