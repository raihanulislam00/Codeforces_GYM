#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int h, m, x;
        cin >> h >> m >> x;

        double ho = (h % 12 + m / 60.0) * 30.0;
        double mi = m * 6.0; 
        
        int ho_B = (h + x) % 12;
        if (ho_B == 0) ho_B = 12;
        
        double hor = (ho_B % 12 + m / 60.0) * 30.0;

        double a = fabs(ho - hor);
        if (a > 180.0) {
            a = 360.0 - a;
        }

        cout << fixed << setprecision(2) << a << endl;
    }

    return 0;
}
