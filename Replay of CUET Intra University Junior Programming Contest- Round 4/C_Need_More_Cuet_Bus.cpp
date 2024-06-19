#include "bits/stdc++.h"
using namespace std;
 
#define int long long
 
int32_t main () {
  int t = 1;
  cin >> t;
  while (t--) {
      int n, tot = 0, sum = 0, ans = 0;;
      cin >> n;
      vector<pair<int,int>>v;
      for (int i = 0; i < n; i++) {
          int x, y;
          cin >> x >> y;
          v.push_back({y,x});
          tot += x;
      }
      sort(v.begin(), v.end());
      for (int i = 0; i < v.size(); i++) {
          sum += v[i].second;
          if (sum >= (tot+1)/2) {
              ans = v[i].first;
              break;
          }
      }
      cout << ans << "\n";
  }
}