#include<bits/stdc++.h>
using namespace std;

const int MAX_VAL = 100005;

vector<int> spf(MAX_VAL, 0);

void compute_spf() {
    for (int i = 2; i < MAX_VAL; ++i) {
        if (spf[i] == 0) {
            for (int j = i; j < MAX_VAL; j += i) {
                if (spf[j] == 0) {
                    spf[j] = i;
                }
            }
        }
    }
}

int main() {
    compute_spf(); 
    
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        
        vector<int> max_e(MAX_VAL, 0);
        
        for (int i = 0; i < N; ++i) {
            int current = A[i];
            while (current > 1) {
                int prime = spf[current];
                int count = 0;
                while (current % prime == 0) {
                    current /= prime;
                    count++;
                }
                if (count > max_e[prime]) {
                    max_e[prime] = count;
                }
            }
        }
        
        int total_moves = 0;
        for (int i = 0; i < MAX_VAL; ++i) {
            total_moves += max_e[i];
        }
        
        if (total_moves % 2 == 1) {
            cout << "Alice" << endl;
        } else {
            cout << "Bob" << endl;
        }
    }

    return 0;
}
