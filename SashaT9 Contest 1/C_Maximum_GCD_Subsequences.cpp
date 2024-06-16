#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int c[N],a[N];
int main()
{
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        c[x]++;
    }
    for(int d=1;d<N;d++)
    {
        int k=0;
        for(int x=d;x<N;x+=d)k+=c[x];
        a[k]=d;
    }
    for(int i=n;i>=1;i--)a[i]=max(a[i+1],a[i]);
    for(int i=1;i<=n;i++)cout<<a[i]<<" \n"[i==n];
}