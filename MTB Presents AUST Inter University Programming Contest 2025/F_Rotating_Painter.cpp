#include<bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int nt, nb;
        double at, ab;
        cin >> nt >> at >> nb >> ab;

        double ap = at / (2 * tan(PI / nt));
        double a = ab / (2 * tan(PI / nb));
        double d = ab / (2 * sin(PI / nb));

        double r = ap;
        double res;

        if (r <= a) {
            res = (0.5 * ab * a * nb) - (PI * r * r);
        } else if (r >= d) {
            res = 0.0;
        } else {
            double th = acos(a / r);
            double ph = (PI / nb) - th;
            double ta = 0.5 * sqrt(r * r - a * a) * a;
            double aa = ph * (r * r / 2);
            double ca = 2 * nb * (ta + aa);
            res = (0.5 * ab * a * nb) - ca;
        }

        cout << fixed << setprecision(6) << res << "\n";
    }

    return 0;
}