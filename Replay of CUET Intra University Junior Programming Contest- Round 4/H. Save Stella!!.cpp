#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long int ll;
typedef unsigned long long int llu;
typedef double dl;
#define f1(i,n) for(i=1;i<=n;i++)
#define f(i,n) for(i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Max 1000009
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sv(v) sort(v.begin(),v.end())
#define rv(v) reverse(v.begin(),v.end())
#define sa(a,n,i) sort(a+i,a+n+i);
#define sp(n) fixed<<setprecision(n)
#define ms(a,n) memset(a,n,sizeof(a));
#define lb lower_bound
#define ub upper_bound
#define lcm(a,b) (a/__gcd(a,b))*b
#define pii pair<ll,ll>
#define cy cout<<"YES\n"
#define cn cout<<"NO\n"
#define c(x) cout<<x;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
 
ll fx[]={1,-1,0,0};
ll fy[]={0,0,-1,1};
ll n,m,a,b;
 
void bfsbomb(vector<vector<char>> &grid, vector<vector<ll>> &dism, vector<vector<ll>> &vis, vector<vector<ll>> &dis)
{
    ll i,j,l,r,k;
     pair<ll,ll>p,x;
    queue<pair<ll,ll>>q;
    f(i,n)
    {
        f(j,m)
        {
            dis[i][j]=2e18;
        }
    }
    f(i,n)
    {
        f(j,m)
        {
            if(grid[i][j]=='0')
            {
                 q.push({i,j});
                 dis[i][j]=0,vis[i][j]=1;
            }
        }
    }
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        for(k=0;k<4;k++)
        {
            l=fx[k]+x.ff;
            r=fy[k]+x.ss;
            if(l>=0 && r>=0 && l<=n-1 && r<=m-1  &&  vis[l][r]==0)
            {
                dis[l][r]=min(dis[l][r],dis[x.ff][x.ss]+1);
                vis[l][r]=1;
                q.push({l,r});
            }
        }
    }
}
ll bfsstella(vector<vector<char>> &grid, vector<vector<ll>> &dism, vector<vector<ll>> &vis, vector<vector<ll>> &dis)
{
vis.assign(n, vector<ll>(m, 0));  
dism.assign(n, vector<ll>(m, 0));
    queue<pair<ll,ll>>q;
    pair<ll,ll>x;
    q.push({a-1,b-1});
    vis[a-1][b-1]=1;
    ll i,j,l,r,ans=-1,p;
    if(a==n&&b==m){
        ans=0;
        return ans;
    }
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        for(i=0;i<4;i++)
        {
          l=fx[i]+x.ff;
          r=fy[i]+x.ss;
          p=dism[x.ff][x.ss]+1;
          if(l>=0 && r>=0 && l<=n-1 && r<=m-1 && vis[l][r]==0 && p<dis[l][r])
          {
             vis[l][r]=1;
             q.push({l,r});
             dism[l][r]=p;
             if(l==n-1 && r==m-1)
             {
                 ans=dism[l][r];
                 break;
             }
          }
         }
         if(ans!=-1) break;
     }
    return ans;
}
int main()
{
    ll t,ans,g,u,v,i,j,w,c;
    cin>>n>>m;
  vector<vector<ll>> vis(n, vector<ll>(m, 0));
    vector<vector<ll>> dis(n, vector<ll>(m, LLONG_MAX));
    vector<vector<ll>> dism(n, vector<ll>(m, 0));
    vector<vector<char>> grid(n, vector<char>(m));
    f(i,n)
    {
        f(j,m)
        {
            cin>>grid[i][j];
        }
    }
    cin>>a>>b;
    bfsbomb(grid, dism, vis, dis);
    ans=bfsstella(grid, dism, vis, dis);
    if(ans==-1)
        cout<<"Impossible\n";
    else cout<<ans<<endl;
}