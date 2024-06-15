#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        int k = (n - 1) ^ n;
        int ans = 0;
        while (k) {
            if (k & 1) ans++;
            k /= 2;
        }
        cout << ans << '\n';
    }
    
    return 0;
}
