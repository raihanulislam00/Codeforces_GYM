#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int l, r;
        cin >> l >> r;

        int sqrtL = ceil(sqrt(l));
        int sqrtR = floor(sqrt(r));

        int cnt = sqrtR - sqrtL + 1;

        cout << cnt << endl;
    }

    return 0;
}
