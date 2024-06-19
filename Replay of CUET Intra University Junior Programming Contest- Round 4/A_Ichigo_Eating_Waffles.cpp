#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, x;
        cin >> n >> x;
        
        vector<int> a(n);
        int temp = 0;
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            temp += a[i];
        }
        
        int ans = temp / x;
        
        cout << ans << endl;
    }
    
    return 0;
}
