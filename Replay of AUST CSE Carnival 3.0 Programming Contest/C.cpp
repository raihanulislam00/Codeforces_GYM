#include<bits/stdc++.h>
#define ll      long long
#define MOD     1000000007
#define sz      1005
using namespace std;

int n, m, a[sz];
ll dp[sz][sz];
string s,t;


ll FuN(int pos,int pos2)
{
    if(pos2==m)
        return 0;
    if(pos>=n)
        return 1e12;
    if(dp[pos][pos2]!=-1)
        return dp[pos][pos2];
    ll ret = 1e12;

    ret = min(ret, FuN(pos+1,pos2));
    ll c;
    if(pos2==0)
        c = 0;
    else
        c = a[pos+1]+abs((int)t[pos2] - (int)t[pos2-1]);
    if(s[pos]==t[pos2]){

        ret = min(ret, c + FuN(pos+1, pos2+1));
    }
    return dp[pos][pos2] = ret;
}

void Solve()
{
    int i, j, fg=0;
    cin>>n>>m;
    cin>>s>>t;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
    ll ans = FuN(0,0);
    if(ans>=1e12)
        ans = -1;
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,T=1;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        Solve();
    }
    return 0;
}