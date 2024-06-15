#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[1005];

int32_t main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        int x, n;
        cin >> x >> n;
        
        if (n == 1) {
            cout << x << '\n';
        } else {
            if (x <= n) {
                for (int i = 1; i <= n; i++) {
                    int s = (i <= x);
                    cout << s;
                    if (i < n) cout << ' ';
                    else cout << '\n';
                }
            } else {
                x -= n;
                int q = x / (n - 1);
                if (q % 2) {
                    a[1] = ((q + 1) / 2) + 1;
                    a[n] = (q / 2) + 1;
                    for (int i = 2; i <= 1 + x % (n - 1); i++) {
                        a[i] = q + 2;
                    }
                    for (int i = 2 + x % (n - 1); i <= n - 1; i++) {
                        a[i] = q + 1;
                    }
                } else {
                    a[1] = (q / 2) + 1;
                    a[n] = (q / 2) + 1;
                    for (int i = n - 1; i >= n - x % (n - 1); i--) {
                        a[i] = q + 2;
                    }
                    for (int i = n - x % (n - 1) - 1; i >= 2; i--) {
                        a[i] = q + 1;
                    }
                }
                for (int i = 1; i <= n; i++) {
                    cout << a[i];
                    if (i < n) cout << ' ';
                    else cout << '\n';
                }
            }
        }
    }
    
    return 0;
}
