#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string tiles;
        cin >> tiles;

        unordered_map<string, int> tileCount;
        for (int i = 0; i < 28; i += 2) {
            string tile = tiles.substr(i, 2);
            tileCount[tile]++;
        }

        // Check for Thirteen Orphans
        vector<string> terminalAndHonors = {"1p", "9p", "1s", "9s", "1m", "9m", "1z", "2z", "3z", "4z", "5z", "6z", "7z"};
        bool hasAllThirteen = true;
        bool hasExtraTile = false;

        for (const auto& tile : terminalAndHonors) {
            if (tileCount[tile] == 0) {
                hasAllThirteen = false;
                break;
            }
            if (tileCount[tile] > 1) {
                if (hasExtraTile) {
                    hasAllThirteen = false;
                    break;
                }
                hasExtraTile = true;
            }
        }

        // Check for 7 Pairs
        bool isSevenPairs = true;
        int pairCount = 0;
        for (const auto& pair : tileCount) {
            if (pair.second == 2) {
                pairCount++;
            } else if (pair.second != 0) {
                isSevenPairs = false;
                break;
            }
        }

        // Determine the result
        if (hasAllThirteen && hasExtraTile) {
            cout << "Thirteen Orphans" << endl;
        } else if (isSevenPairs && pairCount == 7) {
            cout << "7 Pairs" << endl;
        } else {
            cout << "Otherwise" << endl;
        }
    }

    return 0;
}
