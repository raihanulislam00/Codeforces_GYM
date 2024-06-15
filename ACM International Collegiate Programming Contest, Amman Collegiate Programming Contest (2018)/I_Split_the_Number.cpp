#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int x, n;
        cin >> x >> n;
        
        if (n > x) {
            cout << -1 << endl; 
            continue;
        }
        
        vector<int> result(n, x / n);
        int remainder = x % n;
        
        for (int i = 0; i < remainder; ++i) {
            result[i]++;
        }
        
        sort(result.begin(), result.end());
        
        for (int i = 0; i < n; ++i) {
            if (i != 0) cout << " ";
            cout << result[i];
        }
        cout << endl;
    }
    
    return 0;
}
