#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()

using LL = long long;

// 0-based indexing, query finds in range [first, last]
#define lg(x) (31 - __builtin_clz(x))
const int N = 1e5 + 7;
const int K = lg (N);
int tr[N][K + 1];
namespace sparse_table {
  int f (LL p1, LL p2) { 
    return (p1 & p2); 
  }
  void build(int n, vector <int> &a) {
    for (int i = 0; i < n; i++) tr[i][0] = a[i];
    for (int j = 1; j <= K; j++) {
      for(int i = 0; i + (1 << j) <= n; i++)
        tr[i][j] = f(tr[i][j - 1], tr[i + (1 << (j - 1))][j - 1]);
    }
  }
  int query (int l, int r) {
    int d = lg(r - l + 1);
    return f(tr[l][d], tr[r - (1 << d) + 1][d]);
  }
}

struct node {
  int le, ri, val;
};

vector <int> Tree (4 * N);

void update (int curLeft, int curRight, int l, int r, int val, int pos) {
  if (curLeft > curRight or curLeft > r or curRight < l) return;
  if (curLeft >= l and curRight <= r) {
    Tree[pos] |= val;
    return;
  } 
  int mid = (curLeft + curRight) >> 1;
  update (curLeft, mid, l, r, val, pos * 2);
  update (mid + 1, curRight, l, r, val, pos * 2 + 1);
}
  
void dfs (int curLeft, int curRight, int pos, vector <int> &ans) {
  if (curLeft == curRight) {
    ans[curLeft] = Tree[pos];
    return;
  }
  
  Tree[pos * 2] |= Tree[pos];
  Tree[pos * 2 + 1] |= Tree[pos];
  
  int mid = (curLeft + curRight) >> 1;
  dfs (curLeft, mid, pos * 2, ans);
  dfs (mid + 1, curRight, pos * 2 + 1, ans);
}

int main () {
  cin.tie(nullptr)->ios_base::sync_with_stdio(false);

  int Tc = 1;
  cin >> Tc;
  for (int tc = 1; tc <= Tc; tc++) {
    int n, q;
    cin >> n >> q;
    vector < node > v (q);
    for (auto &i : v) cin >> i.le >> i.ri >> i.val;
    sort (all (v), [&] (node &a, node &b) {
      if (a.val == b.val) return a.ri - a.le > b.ri - b.le;
      return a.val > b.val;
    });

    Tree.assign (4 * n, 0);

    for (auto c : v) update (1, n, c.le, c.ri, c.val, 1);

    vector <int> ans (n + 1);
    dfs (1, n, 1, ans);
    for (int i = 0; i < n; i++) ans[i] = ans[i + 1]; 

    bool good = true;
    sparse_table::build (n, ans);
    for (auto c : v) {
      int x = sparse_table::query (c.le - 1, c.ri - 1);
      if (x != c.val) {
        good = false;
        break;
      }
    }

    if (not good) cout << "No" << '\n';
    else {
      cout << "Yes" << '\n';
      for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
    }
  }

  return 0;
}