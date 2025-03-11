#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define ALL(x) x.begin(),x.end()

const int N = 3e5 +5;
const int oo = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        int n, k; cin >> n >> k;
        vector<int> a(n+1, -1);
        queue<int> q;
        q.push(0);
        a[0] = 0;
        while(!q.empty()) {
            int x = q.front(); q.pop();
            int r = min(k+x, -k+2*n-x);
            int l = max(k-x, x-k);
            int s = 10;
            for(int i=l; i<=r; i+=2) {
                if(a[i] == -1) {
                    a[i] = a[x]+1;
                    q.push(i);
                } else if(s-- > 0) continue;
                else break;
            }
            s = 10;
            for(int i=r; i>=l; i-=2) {
                if(a[i] == -1) {
                    a[i] = a[x]+1;
                    q.push(i);
                } else if(s-- > 0) continue;
                else break;
            }
        }
        for(int i=1; i<=n; i++) cout << a[i] << " ";
        cout << "\n";
    }
    return 0;
}