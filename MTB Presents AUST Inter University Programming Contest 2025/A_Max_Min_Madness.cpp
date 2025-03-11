#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int MAX = 2e6 + 6;

long long inv(long long a, long long b = MOD) {
    return 1 < a ? b - inv(b % a, a) * b / a : 1;
}

int fct[MAX], iv[MAX];

void pre() {
    fct[0] = 1;
    for (int i = 1; i < MAX; i++) fct[i] = 1LL * fct[i - 1] * i % MOD;
    iv[MAX - 1] = inv(fct[MAX - 1]);
    for (int i = MAX - 2; i >= 0; i--) iv[i] = (1LL * iv[i + 1] * (i + 1)) % MOD;
}

int ncr(int n, int r) {
    return r > n ? 0 : (((1LL * fct[n] * iv[r]) % MOD) * iv[n - r]) % MOD;
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    pre();
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &x : v) cin >> x;
        int ans = 0;
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) 
            if (v[i]) ans = (ans + (ncr(i + 1 + v[i] - 1, i + 1) - 1 + MOD) % MOD + 1) % MOD;
        cout << ans << '\n';
    }
}