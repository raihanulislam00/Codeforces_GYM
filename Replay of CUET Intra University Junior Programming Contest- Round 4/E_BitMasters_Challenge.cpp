#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve() {
    
    ll g, h, i, j;
    cin >> g >> h >> i >> j;

    ll a = 0, b = 0, c = 0;

    for(int x = 0; x < 30; x++) {
        int temp = (1<<x);
        // 1 3
        if((g & temp)) {
            int cnt = 0;
            if((h & temp)) cnt++;
            if((i & temp)) cnt++;
            if((j & temp)) cnt++;
            a += temp;
            if(cnt == 3) {
                b += temp; c += temp;
            }
            else if(cnt > 0){
                cout << -1 << endl;return;
            }
        }
        else {
            int cnt = 0;
            if((h & temp)) cnt++;
            if((i & temp)) cnt++;
            if((j & temp)) cnt++;
            if(cnt > 1) {
                cout << -1 << endl;return;
            }
            if((h & temp)) a += temp, b += temp;
            if((i & temp)) b += temp, c += temp;
            if((j & temp)) a += temp, c += temp;
        }
    }
    cout << a << " " << b << " " << c << endl;

}
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
       solve();
    }
}