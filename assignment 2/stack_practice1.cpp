#include <bits/stdc++.h>
using namespace std;
int main(){
    stack <int> st;
    int n;
    cin>>n;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x){
            st.push(x);
        }
        else{
            cout<<st.top();
            st.pop();
        }
    }
    return 0;
}
