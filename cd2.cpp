#include <iostream>
using namespace std;
int main() {
    int t;
    cin>>t;
    string s;
    int count;
    while(t--){
        cin>>s;
        count=0;
        for(int i=1;i<s.size();i++){
            if(s[i-1]=='1'&&s[i]=='0'){
                count++;
            }
        }
        cout<<(count+1)<<endl;
    }
    
    return 0;
}
