#include <iostream>
using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;

    long long result = 1;
    long long base = 2;
    int exponent = n - 1;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exponent /= 2;
    }

    cout << result << endl;

    return 0;
}
