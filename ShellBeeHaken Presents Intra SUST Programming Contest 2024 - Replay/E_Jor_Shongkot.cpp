#include <bits/stdc++.h>
using namespace std;

#define int int64_t

int32_t main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int x = 0;
    for (int i = 1; i <= n; i++)
        x ^= i;
    for (int i = 0; i < n; i++)
        x ^= a[i];
    set<int> st;
    for (int i = 0; i < n; i++)
        st.insert(a[i] ^ x);
    bool ok = true;
    for (int i = 1; i <= n; i++)
        ok &= st.find(i) != st.end();
    cout << (ok ? "YES\n" : "NO\n");
}