#include <bits/stdc++.h>
using namespace std;

#define files                        \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

#ifdef LOCAL
#include "E:\Codes\Codes\_Debug.cpp"
#else
#define debug(...)
#endif

#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define ll long long
#define int long long

const ll MOD = 1e9 + 7;
const int MXN = 5e5 + 5;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};


int n, m;
ll aa[MXN];

vector<long long> lg, two;
vector<vector<long long>> st;

void build()
{
    lg.resize(n + 1);
    lg[0] = lg[1] = 0;

    for (int ii = 2; ii <= n; ++ii)
        lg[ii] = lg[ii / 2] + 1;

    two.resize(lg[n] + 1);
    for (int ii = two[0] = 1; ii <= lg[n]; ++ii)
        two[ii] = two[ii - 1] * 2;

    st.resize(n, vector<long long>(lg[n] + 1));

    for (int ii = 0; ii < n; ii++)
        st[ii][0] = aa[ii];
    for (int jj = 1; jj <= lg[n]; jj++)
        for (int ii = 0; ii + two[jj] <= n; ii++)
        {
            long long x = st[ii][jj - 1];
            long long y = st[ii + two[jj - 1]][jj - 1];

            st[ii][jj] = __gcd(x, y);
        };
}

ll query(int L, int R)
{
    int jj = lg[(R - L + 1)];
    long long x = st[L][jj];
    long long y = st[R - two[jj] + 1][jj];
    return __gcd(x, y);
}


void sol(int tc)
{
    cin >> n >> m;
    for (int ii = 0; ii < n; ++ii) cin >> aa[ii];
    
    build();

    for (int ii = 0; ii < m; ++ii)
    {
        int id;
        ll x;
        cin >> id >> x;
        --id;

        int low = id - 1, high = n;
        while (high - low > 1)
        {
            int mid = (low + high) / 2;
            ll cur = query(id, mid);
            
            // debug(id, mid, cur);

            if (cur >= x) low = mid;
            else high = mid;
        }
        cout << low - id + 1 << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    for (int ii = 1; ii <= T; ++ii)
        sol(ii);
}