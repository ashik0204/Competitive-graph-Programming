#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> degree(n + 1, 0);
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            degree[x]++;
            degree[y]++;
        }
        
        int leaves = 0;
        for (int i = 1; i <= n; i++) {
            if (degree[i] == 1) { 
                leaves++;
            }
        }
        
        cout << (leaves + 1) / 2 << endl;
    }
    return 0;
}
