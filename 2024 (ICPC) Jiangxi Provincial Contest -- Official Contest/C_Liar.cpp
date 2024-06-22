#include <iostream>
using namespace std;

int main() {
    int n;
    long long s;
    cin >> n >> s;

    long long sumA = 0;
    for (int i = 0; i < n; ++i) {
        long long ai;
        cin >> ai;
        sumA += ai;
    }

    if (sumA == s) {
        cout << n << endl;
    } else {
        cout << n - 1 << endl;
    }

    return 0;
}
