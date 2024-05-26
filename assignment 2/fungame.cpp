#include <bits/stdc++.h>
using namespace std;
void func(int* a,int n){
    int A=0;
    int B=n-1;
    while(A<n&&B>=0){
        if(a[A]>a[B]){
            cout<<1<<" ";
            B--;
        }
        else if(a[A]<a[B]){
            cout<<2<<" ";
            A++;
        }
        else{
            cout<<0<<" ";
            A++;
            B--;
        }
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    func(a,n);
}
