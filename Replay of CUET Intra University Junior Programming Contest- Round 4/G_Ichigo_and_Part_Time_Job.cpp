#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
vector<int> ara[N+5], val(N+5), ans(N+5), dist(N+5);
 
void dfs(int u, int p, int h)
{
    dist[u] = h;
 
    for(auto v: ara[u]){
        if(v != p){
            dfs(v, u, h+1);
            if(ans[v] || val[v]) ans[u] += ans[v] + 2;
        }
    }
}
signed main()
{
    int t = 1; 
    for(int cs = 1; cs <= t; cs++){
 
        int n, q; cin >> n >> q;
 
        for(int K = 1; K <= n; K++){
            cin >> val[K];
            ara[K].clear();
            dist[K] = ans[K] = 0;
        }
 
        for(int K = 1; K < n; K++){
            int u, v; cin >> u >> v;
            ara[u].push_back(v);
            ara[v].push_back(u);
        }
 
        dfs(1, 1, 0);
 
        while(q--){
            int x; cin >> x;
 
            int sol = dist[x]*2 + ans[x];
            if(ans[x] == 0 && val[x] == 0) sol = 0;
            cout << sol << "\n";
        }
    }
 
    return 0;
}