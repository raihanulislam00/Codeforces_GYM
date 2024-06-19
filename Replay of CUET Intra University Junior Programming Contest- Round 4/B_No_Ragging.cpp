#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll X, K, D;
    cin >> X >> K >> D;
    
    X = abs(X);
    ll move = min(K, X / D);
    K -= move;
    X -= move * D;

    if (K % 2 == 0) {
        cout << X << endl;
    } else {
        cout << D - X << endl;
    }

    return 0;
}
