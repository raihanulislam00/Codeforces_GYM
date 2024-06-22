#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MOD = 5;

// Function to calculate power with modulo
int power(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    
    vector<string> results;
    
    while (T--) {
        int n;
        cin >> n;
        
        int remainder = 0;
        
        for (int i = 0; i < n; ++i) {
            int x;
            string b;
            cin >> x >> b;
            
            int y;
            if (b == "A") {
                y = 10;
            } else {
                y = b[0] - '0';
            }
            
            // Update remainder based on current pair (x, y)
            remainder = (remainder * power(11, x, MOD) + y) % MOD;
        }
        
        if (remainder == 0) {
            results.push_back("Yes");
        } else {
            results.push_back("No");
        }
    }
    
    for (const string& result : results) {
        cout << result << "\n";
    }
    
    return 0;
}
