#include <bits/stdc++.h>
using namespace std;

#define files                        \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

#ifdef LOCAL
#include "E:\Codes\Codes\_Debug.cpp"
#else
#define debug(...)
#endif

#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define ll long long

const ll MOD = 1e9 + 7;
const int MXN = 2150;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int node;
vector<vector<int>> adj;
vector<vector<pair<int, int>>> queries;
vector<int> ancestor;
vector<bool> visited;
vector<int> res;

int par[MXN];
int len[MXN];

int f(int x)
{
    return par[x] = x == par[x] ? x : f(par[x]);
}
void unite(int x, int y)
{
    x = f(x);
    y = f(y);
    if (x != y)
    {
        if (len[x] < len[y]) swap(x, y);
        par[y] = par[x];
        len[x] += len[y];
    }
}
void dfs(int v)
{
    visited[v] = true;
    ancestor[v] = v;
    for (int u : adj[v])
    {
        if (!visited[u])
        {
            dfs(u);
            unite(v, u);
            ancestor[f(v)] = v;
        }
    }
    for (auto other_node : queries[v])
    {
        if (visited[other_node.first])
            res[other_node.second] = ancestor[f(other_node.first)];
    }
}

void compute_LCAs()
{
    ancestor.resize(node);
    visited.assign(node, false);
    for (int ii = 0; ii < node; ++ii)
    {
        par[ii] = ii;
        len[ii] = 1;
    }
    dfs(0);
}

void sol(int tc)
{
    cin >> node;    
    adj.resize(node);
    queries.resize(node);
    for (int ii = 1; ii < node; ++ii)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int m;
    cin >> m;
    res.resize(m);
    for (int ii = 0; ii < m; ++ii)
    {
        int u, v;
        cin >> u >> v;
        queries[u].push_back({v, ii});
        queries[v].push_back({u, ii});
    }
    compute_LCAs();
    for (int ii = 0; ii < m; ++ii)
        cout << res[ii] << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    for (int ii = 1; ii <= T; ++ii)
        sol(ii);
}