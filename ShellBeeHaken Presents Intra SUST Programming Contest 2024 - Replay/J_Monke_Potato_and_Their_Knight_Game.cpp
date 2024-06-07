#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int dx = abs(x1 - x2);
        int dy = abs(y1 - y2);
        int sum = dx + dy;

        if (sum % 2 == 1) {
            cout << "Monke\n";
        } else {
            cout << "Potato\n";
        }
    }

    return 0;
}
