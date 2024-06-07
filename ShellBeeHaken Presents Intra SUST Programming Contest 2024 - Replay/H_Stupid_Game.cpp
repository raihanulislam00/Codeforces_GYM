#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; 
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n; 
        cin >> n;

        string winner;
        if (n % 2 == 0) {
            winner = "No words";
        } else {
            winner = (n == 1 || n % 4 == 1) ? "Beautiful game" : "Never playing this again";
        }

        cout << winner << endl; 
    }
    return 0;
}
