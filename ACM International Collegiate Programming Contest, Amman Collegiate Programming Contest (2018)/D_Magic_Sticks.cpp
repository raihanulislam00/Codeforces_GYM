#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

ll sol(ll n, ll m) {
    return n * ((m + 1) / 2) + ((m + 1) % 2) * (n / 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        ll n, m;
        cin >> n >> m;

        ll xx = min(sol(n, m), sol(m, n));
        cout << xx << '\n';
    }

    return 0;
}
