#include<bits/stdc++.h>
using namespace std;

using ll = long long;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--){
        int n, s; cin >> n >> s;
        vector<pair<string,pair<string,int>>> v;
        for(int i = 0; i < n; i++){
            string temp; cin >> temp;
            string a = temp;
            sort(temp.begin(), temp.end());
            v.push_back({temp,{a, i+1}});
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < n; i++){
            cout << v[i].second.second << " \n"[i + 1 == n];
        }
    }
    return 0;
}