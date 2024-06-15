#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[100005], b[1000005], c[100005];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            b[a[i]] = a[i];
            c[i] = a[i];
        }

        sort(a + 1, a + 1 + n);
        int k = unique(a + 1, a + 1 + n) - (a + 1);
        
        for (int i = 1; i <= k; i++) {
            for (int j = a[i]; j <= a[k]; j += a[i]) {
                if (b[j] == j) b[j] = b[a[i]];
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += b[c[i]];
        }

        cout << ans << '\n';
    }

    return 0;
}
