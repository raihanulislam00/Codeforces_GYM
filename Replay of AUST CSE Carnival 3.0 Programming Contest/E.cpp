#include<bits/stdc++.h>
#define ll      long long
#define MOD     1000000007
#define sz      200005
using namespace std;

int n, a[10005];
ll dp[10005][3];
unordered_map<int,int> m;
bool isprime(int value)
{
    if(value%2==0)
        return 0;
    for(ll i=3;i*i<=value;i+=2)
    {
        if(value%i==0)
            return 0;
    }
    return 1;
}

ll FuN(int pos,int prime)
{
    if(pos>n)
        return 1;
    if(dp[pos][prime]!=-1)
        return dp[pos][prime];
    ll ret = FuN(pos+1, prime)%MOD;
    if(m[a[pos]])
    {
        if(prime!=1)
            ret = (ret + FuN(pos+1,1))%MOD;
    }
    else
    {
        if(prime!=0)
            ret = (ret + FuN(pos+1,0))%MOD;
    }
    return dp[pos][prime] = ret;
}

void Solve(int t)
{
    int i, j, ans =0, fg=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        if(m.find(a[i])==m.end())
            m[a[i]] = isprime(a[i]);
    }
    memset(dp,-1,sizeof(dp));
    ans = (FuN(1,2)-1+MOD)%MOD;
    cout<<ans<<endl;
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

