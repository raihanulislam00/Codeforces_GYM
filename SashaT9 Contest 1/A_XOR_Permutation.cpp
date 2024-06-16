#include<bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int x) {
    return (x > 0) && ((x & (x - 1)) == 0);
}

int main() {
    int n;
    cin >> n;

    if (isPowerOfTwo(n + 2)) {
        cout << n + 1 << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
