#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    pair<int, int> start, end;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            if (v[i][j] == 'A') {
                start = {i, j};
            } else if (v[i][j] == 'B') {
                end = {i, j};
            }
        }
    }

    vector<vector<int>> me_adj(n * m);
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<char> direction_labels = {'D', 'U', 'R', 'L'};
    
    auto get_pos = [&](int i, int j) {
        return i * m + j;
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] != '#') {
                int current = get_pos(i, j);
                for (int d = 0; d < directions.size(); d++) {
                    int ni = i + directions[d].first;
                    int nj = j + directions[d].second;
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && v[ni][nj] != '#') {
                        int neighbor = get_pos(ni, nj);
                        me_adj[current].push_back(neighbor);
                    }
                }
            }
        }
    }

    int start_pos = get_pos(start.first, start.second);
    int end_pos = get_pos(end.first, end.second);
    
    vector<int> vis(n * m, 0);
    vector<int> prev(n * m, -1);
    vector<char> path_direction(n * m);
    queue<int> q;
    q.push(start_pos);
    vis[start_pos] = 1;

    while (!q.empty()) {
        int t = q.front();
        q.pop();
        if (t == end_pos) {
            string path;
            for (int at = end_pos; at != start_pos; at = prev[at]) {
                path += path_direction[at];
            }
            reverse(path.begin(), path.end());
            cout << "YES" << endl;
            cout << path.length() << endl;
            cout << path << endl;
            return 0;
        }
        for (int i = 0; i < me_adj[t].size(); i++) {
            int neighbor = me_adj[t][i];
            if (!vis[neighbor]) {
                vis[neighbor] = 1;
                prev[neighbor] = t;
                for (int d = 0; d < directions.size(); d++) {
                    int ni = (t / m) + directions[d].first;
                    int nj = (t % m) + directions[d].second;
                    if (get_pos(ni, nj) == neighbor) {
                        path_direction[neighbor] = direction_labels[d];
                        break;
                    }
                }
                q.push(neighbor);
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}
