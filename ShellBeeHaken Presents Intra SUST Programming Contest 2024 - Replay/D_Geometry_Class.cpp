#include<bits/stdc++.h>
using namespace std;
#define pi 3.14159265359
int main() {
    int n;
    cin >> n;
    for (int t = 0; t < n; ++t) {
        vector<double> v(3);
        for (int i = 0; i < 3; ++i) {
            cin >> v[i];
        }
        
        sort(v.begin(), v.end());
        double x = v[0], y = v[1], z = v[2];

        double fr = 180.0 * (asin(x) / pi + asin(y) / pi);
        fr = round(fr);
        double result = 180.0 - fr;

        cout << result << endl;
    }
    return 0;
}
