#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, k, l;
    cin >> n >> m >> k >> l;

    vector<vector<int>> I(n + 1, vector<int>(m + 1));
    vector<vector<int>> P(n + 1, vector<int>(m + 1));

    // Read matrix I and calculate prefix sums
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> I[i][j];
            P[i][j] = I[i][j];
            if (i > 1) P[i][j] += P[i - 1][j];
            if (j > 1) P[i][j] += P[i][j - 1];
            if (i > 1 && j > 1) P[i][j] -= P[i - 1][j - 1];
        }
    }

    int max_sum = -1e9; // Initialize to a very small value

    // Iterate through all possible positions to place K
    for (int p = 1; p <= n - k + 1; ++p) {
        for (int q = 1; q <= m - l + 1; ++q) {
            int current_sum = 0;

            // Calculate the sum of the submatrix I[p, p+k-1][q, q+l-1]
            for (int x = p; x < p + k; ++x) {
                for (int y = q; y < q + l; ++y) {
                    int sum = P[x][y];
                    if (x > p) sum -= P[p - 1][y];
                    if (y > q) sum -= P[x][q - 1];
                    if (x > p && y > q) sum += P[p - 1][q - 1];

                    // Calculate the contribution of K[x-p+1][y-q+1]
                    if (sum > 0)
                        current_sum += 1;
                    else if (sum < 0)
                        current_sum -= 1;
                }
            }

            // Update max_sum if current_sum is larger
            max_sum = max(max_sum, current_sum);
        }
    }

    cout << max_sum << endl;

    return 0;
}
