#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> A(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }

        int ways = 0;
        for (int i = 0; i < n; ++i) {
            A[i] = -A[i];
            int sum = 0;
            for (int j = 0; j < n; ++j) {
                sum += A[j];
            }
            if (sum % 2 == 0)
                ways++;

            A[i] = -A[i];
        }

        cout << ways << endl;
    }

    return 0;
}
