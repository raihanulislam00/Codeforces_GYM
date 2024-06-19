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
const int MXN = 105005;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

long long bin(long long base, long long pow, long long m)
{
    if (base >= m)
        base %= m;
    long long res = 1;
    while (pow)
    {
        if (pow & 1)
        {
            res = res * base;
            if (res >= m)
                res %= m;
        }
        base = base * base;
        if (base >= m)
            base %= m;
        pow >>= 1;
    }
    return res;
}

ll fact[MXN];
ll inv[MXN];

void sol(int tc)
{
    int n, k, y;
    cin >> k >> n >> y;

    auto nCr = [&](int nn, int rr)
    {
        ll res = fact[nn] * inv[rr] % MOD;
        res = res * inv[nn - rr] % MOD;
        return res;
    };
    ll ans = 0;
    for (int ii = 0; ii <= n; ++ii)
    {
        int has = y - k * ii - n;
        if (has < 0) break;
        int to = n - ii;

        ll cur = nCr(n, ii);
        cur = cur * nCr(has + n - 1, n - 1) % MOD;
        if (ii % 2) ans -= cur;
        else ans += cur;
        if (ans < 0) ans += MOD;
        if (ans >= MOD) ans -= MOD;
        
        // debug(ii, has, to, cur);
    }
    cout << "Case " << tc << ": ";
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int ii = fact[0] = inv[0] = 1; ii < MXN; ++ii)
    {
        fact[ii] = fact[ii - 1] * ii % MOD;
        inv[ii] = bin(fact[ii], MOD - 2, MOD);
    }

    int T = 1;
    cin >> T;
    for (int ii = 1; ii <= T; ++ii)
        sol(ii);
}
