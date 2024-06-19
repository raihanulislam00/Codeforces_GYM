#include<bits/stdc++.h>
#define ll      long long
#define MOD     1000000007
#define sz      200005
using namespace std;

ll n,m,k, a[sz], vis[sz],mn;
vector<ll> graph[sz];

void DFS(ll u)
{
    vis[u] = 1;
    mn = min(mn, a[u]);
    for(auto v:graph[u])
    {
        if(!vis[v])
            DFS(v);
    }
}
void Solve(int t)
{
    ll i, j, ans =1, fg=0,u,v;
    cin>>n>>m>>k;
    for(i=1;i<=m;i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    vector<ll> vec;
    for(i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            mn = 1e12;
            DFS(i);
            vec.push_back(mn);
        }
    }
    sort(vec.begin(),vec.end());
    int last = 0;
    vector<ll> v2;
    for(i=1;i<vec.size();i++)
    {
        if(abs(vec[i]-vec[i-1])>k){
            v2.push_back(i-last);
            last = i;
            ans++;
        }
    }
    v2.push_back(vec.size()-last);
    sort(v2.begin(),v2.end());
    cout<<v2.size()<<' '<<v2.back()<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,T=1;
//    cin>>T;
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}
