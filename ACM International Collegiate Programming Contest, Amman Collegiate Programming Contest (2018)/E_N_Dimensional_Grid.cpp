#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

int a[100005], in[100005];

ll mypow(ll x, int y) {
    ll ans = 1;
    while (y) {
        if (y & 1) ans = ans * x % mod;
        x = x * x % mod;
        y /= 2;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        ll ak = 1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            in[a[i]]++;
            ak = ak * a[i] % mod;
        }

        ll ans = 0;
        sort(a + 1, a + 1 + n);
        int k = unique(a + 1, a + 1 + n) - a - 1;

        for (int i = 1; i <= k; i++) {
            ans = (ans + in[a[i]] * (ak * mypow((ll)a[i], mod - 2) % mod * (a[i] - 1) % mod) % mod) % mod;
            in[a[i]] = 0;
        }

        cout << ans << '\n';
    }

    return 0;
}
