#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    vector<int> q(m);
    for (int i = 0; i < m; ++i) {
        cin >> q[i];
    }
    
    vector<int> e(n);
    map<int, int> cnt;
    
    for (int i = 0; i < n; ++i) {
        int exp = 0;
        while (arr[i] % 2 == 0) {
            arr[i] /= 2;
            ++exp;
        }
        e[i] = exp;
        cnt[exp]++;
    }
    
    auto gcd_mod_2_exp = [](int exp) {
        long long result = 1;
        long long base = 2;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    };
    
    vector<long long> results;
    for (int q : q) {
        int idx = q - 1;
        int old_exp = e[idx];
        int new_exp = old_exp + 1;
        
        cnt[old_exp]--;
        if (cnt[old_exp] == 0) {
            cnt.erase(old_exp);
        }
        cnt[new_exp]++;
        
        e[idx] = new_exp;
        
        int min_exp = cnt.begin()->first;
        
        results.push_back(gcd_mod_2_exp(min_exp));
    }
    
    for (long long result : results) {
        cout << result << "\n";
    }
    
    return 0;
}
