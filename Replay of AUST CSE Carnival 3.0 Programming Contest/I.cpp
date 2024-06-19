#include<bits/stdc++.h>
using namespace std;
#define int long long
bool isXRoot(int N, int X) {
    if (X == 1) {
        return true;
    }
    
    int lo = 2;
    int hi = pow(N, 1.0 / X) + 1;
    
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int power = 1;
        
        for (int i = 0; i < X; ++i) {
            if (__builtin_mul_overflow(power, mid, &power)) {
                break;
            }
        }
        
        if (power == N) {
            return true;
        }
        
        if (power > N || power < 0) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    
    return false;
}

int32_t main() {
    int N;
    int X;
    cin >> N >> X;
    
    if (isXRoot(N, X)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
