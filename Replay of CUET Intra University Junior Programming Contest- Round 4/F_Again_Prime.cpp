#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define db double
#define pii pair<ll,ll>
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fr(i,a,b) for(ll i=a;i>=b;i--)
#define pb push_back
#define ss second
#define ff first
#define in insert
#define sq(x)  (x*x)
#define all(a)  a.begin(),a.end()
#define nl '\n'
ll gcd(ll a,ll b){
       if(b==0)return a;
       return gcd(b,a%b);
}
ll lcm(ll a,ll b){
       return (a*b)/gcd(a,b);
}
const ll  N = 2100005;
const ll mod = 1e8;
const ll neginf= -1e18;
const ll inf = 1e15;
bool com(pair<ll,ll>p,pair<ll,ll>q){
   return p.ff<q.ff;
}
bool fun(ll d){
   for(ll i=2;i*i<=d;i++){
      if(d%i==0)return false;
   }
   return true;
}
ll prime[2100005];
void seive(){
 
        prime[0]=1;
        prime[1]=1;
 
        for(ll i=4;i<=N;i+=2){
            prime[i]=1;
        }
 
        for(ll i=3;i*i<=N;i+=2){
            if(prime[i]==0){
                for(ll j=i*i;j<=N;j+=2*i){
                    prime[j]=1;
                }
            }
        }
}
int main(){
 
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       cout.tie(NULL);
 
       seive();
 
       ll a,b;
       cin>>a>>b;
 
       vector<ll>v;
 
       f(i,a,b+1){
          if(prime[i]==0){
             v.pb(i);
          }
       }
 
 
       ll ct=0;
         for( int i = 0 ; i < ( 1 << v.size() ) ; ++ i ) {
 
          ll sm=0;
        for ( int j = 0; j < v.size() ; ++ j ) {
            if ( ( i & ( 1 << j ) ) != 0 )
                sm += v [j] ;
        }
 
         if(prime[sm]==0&&sm>0)ct++;
 
       }
       cout<<ct;
}