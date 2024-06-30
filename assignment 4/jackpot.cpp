#include<bits/stdc++.h>
char* solve(int* A, int n1, int* B, int n2) {
    int possibleValues[1000];
    possibleValues[0]=0);  // Start with 0 money

    for (int i=0;i<n1;i++) {
        int num=A[i];
        unordered_set<int> newValues;
        for (int val : possibleValues) {
            newValues.insert(val ^ num);
        }
        possibleValues.insert(newValues.begin(), newValues.end());
    }

    char result[n2];
    for (int i=0;i<n2;i++) {
        int cost=B[i];
        int flag=0;
        
        for(int val:possibleValues){
            if(cost%val==0){
                break
                flag=1;
            }
            else{
                cost=cost%val;
            }
        }
        if(flag){
            result[i]='1';
        }
        else{
            result[i]='0';
        }
    }

    return result;
}
