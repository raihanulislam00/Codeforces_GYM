#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    // Step 1: Find the initial minimum value in the grid
    int min_val = grid[0][0];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            min_val = min(min_val, grid[i][j]);
        }
    }

    // Step 2: Adjust each row to min_val
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            grid[i][j] = min_val;
        }
    }

    // Step 3: Adjust each column to min_val
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            grid[i][j] = min_val;
        }
    }

    // Output the maximum possible minimum value
    cout << min_val << endl;

    return 0;
}
