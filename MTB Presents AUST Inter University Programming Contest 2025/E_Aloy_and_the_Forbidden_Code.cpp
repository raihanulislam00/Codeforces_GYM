#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    
    int n = s.length();
    int ans = n;
    
    int left = 0;
    vector<int> count(3, 0);
    int d = 0;
    
    for (int right = 0; right < n; right++) {
        count[s[right] - 'a']++;
        if (count[s[right] - 'a'] == 1) {
            d++;
        }
        
        while (d == 3) {
            ans = min(ans, right - left + 1);
            count[s[left] - 'a']--;
            if (count[s[left] - 'a'] == 0) {
                d--;
            }
            left++;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}