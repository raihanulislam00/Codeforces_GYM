#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        // Calculate array B
        vector<int> b(n);
        b[0] = a[0];
        for (int i = 1; i < n; ++i) {
            if (i < k) {
                b[i] = a[i] - a[i - 1];
            } else {
                b[i] = a[i] + b[i - k] - a[i - 1];
            }
        }
        
        // Find maximum length sub-array where all elements are > 0
        int maxStreak = 0;
        int currentStreak = 0;
        
        for (int i = 0; i < n; ++i) {
            if (b[i] > 0) {
                currentStreak++;
                maxStreak = max(maxStreak, currentStreak);
            } else {
                currentStreak = 0;
            }
        }
        
        cout << maxStreak << endl;
    }
    return 0;
}
