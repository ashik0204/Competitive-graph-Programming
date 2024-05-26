class Solution {
public:
    bool isValid(string s) {
        map <char,int> m={{'(',-1},{'[',-2},{'{',-3},{')',1},{']',2},{'}',3}};
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(m[s[i]]>0){
                if(st.empty()){
                    return false;
                }
                if(st.top()+m[s[i]]!=0){
                    return false;
                }
                else{
                    st.pop();
                }
            }
            else{
                st.push(m[s[i]]);
            }
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
};
