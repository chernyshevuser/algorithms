#include "levenshtein_distance.h"

namespace levenshtein_distance {

    using std::array;
    using std::vector;
    using std::string;
    using std::min;

    int ComputeLevenshteinDistance(const string &first, const string &second) {
        if (first.size() < second.size()) {
            return ComputeLevenshteinDistance(second, first);
        }

        array<vector<int>, 2> dp;
        vector<int> tmp(second.size() + 1);
        fill(dp.begin(), dp.end(), tmp);

        iota(dp[0].begin(), dp[0].end(), 0);

        for (int i = 1; i < first.size() + 1; i++) {
            dp[1][0] = i;
            for (int j = 1; j < second.size() + 1; j++) {
                if (first[i - 1] == second[j - 1]) {
                    dp[1][j] = dp[0][j - 1];
                } else {
                    dp[1][j] = min({dp[0][j] + OPERATION_COST,
                                    dp[1][j - 1] + OPERATION_COST,
                                    dp[0][j - 1] + OPERATION_COST});
                }
            }

            dp[0] = dp[1];
        }

        return dp[1][second.size()];
    }

    void RunProgram() {
        using std::cin;
        using std::cout;
        using std::endl;

        string first, second;
        cin >> first >> second;

        cout << ComputeLevenshteinDistance(first, second) << endl;

    }

}