#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    int n, m;
    
    cin >> n;
    vector<vector<int>> t(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        t[u].push_back(v);
        t[v].push_back(u);
    }

    cin >> m;
    vector<vector<int>> t2(m + 1);
    for (int i = 0; i < m - 1; ++i) {
        int u, v;
        cin >> u >> v;
        t2[u].push_back(v);
        t2[v].push_back(u);
    }

    auto bfs = [](int start, const vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        int fs = start;
        int max_dist = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                    if (dist[neighbor] > max_dist) {
                        max_dist = dist[neighbor];
                        fs = neighbor;
                    }
                }
            }
        }
        return make_pair(fs, max_dist);
    };

    auto result1 = bfs(1, t);
    auto result2 = bfs(result1.first, t);
    int diam1 = result2.second;

    auto result3 = bfs(1, t2);
    auto result4 = bfs(result3.first, t2);
    int diam2 = result4.second;

    int part1 = (diam1 + 1) / 2;
    int part2 = (diam2 + 1) / 2;
    int new_diameter = max(max(diam1, diam2), part1 + part2 + 1);

    cout << new_diameter << endl;

    return 0;
}
