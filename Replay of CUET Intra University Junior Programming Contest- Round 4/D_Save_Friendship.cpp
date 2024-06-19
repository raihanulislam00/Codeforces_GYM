#include<bits/stdc++.h>
#include<iostream>
#define ll long long
#define pb push_back
using namespace std;

void solve() {
    ll n,m;
    cin >> n >> m;
    ll array[n+1],prefix_xor[n+1] = {0};

    for(ll i = 1; i <= n; i++) {
        cin >> array[i];
        prefix_xor[i] = (array[i]^prefix_xor[i-1]);
    }
    ll ans = -1;
    for(ll i = m; i <= n; i++) {
        ll Xor = prefix_xor[i]^prefix_xor[i-m];
        if(Xor == 0) continue;

        bool ok = false;
        for(ll j = 29; j >= 0; j--) {
            ll bit = (1<<j)&Xor;
            if(bit) ok = true;

            if(ok) {
                ll new_value = Xor^(1<<j);
                ans = max(ans,new_value);
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ll t = 1;

    //cin >> t;

    while(t--) {
        solve();
    }
}