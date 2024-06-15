#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        vector<int> happiness(2 * n);
        
        for (int i = 0; i < 2 * n; ++i) {
            cin >> happiness[i];
        }
        
        int max_happiness = 0;
        for (int i = 0; i < n; ++i) {
            int pair_happiness = happiness[i] + happiness[2 * n - i - 1];
            max_happiness = max(max_happiness, pair_happiness);
        }
        
        cout << max_happiness << endl;
    }
    
    return 0;
}
