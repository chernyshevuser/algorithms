#include "equal_sum.h"

namespace equal_sum {
    using std::vector;

    bool IsPossiblePartition(vector<int> &nums) {
        int numsSum = accumulate(nums.begin(), nums.end(), 0);

        if (numsSum % 2 != 0 or nums.size() == 1) {
            return false;
        }

        sort(nums.begin(), nums.end(), [](int lhs, int rhs) {
            return lhs >= rhs;
        });
        int halfSum = numsSum / 2;
        vector<bool> dp(halfSum + 1, false);

        for (int i = 0; i < nums.size(); i++) {
            for (int j = halfSum; j >= nums[i]; j--) {
                if (j > nums[i] and dp[j - nums[i]]) {
                    dp[j] = true;
                } else if (j == nums[i]) {
                    dp[j] = true;
                }
            }
        }

        return dp[halfSum];
    }

    void RunProgram() {
        using std::cin;
        using std::cout;
        using std::endl;

        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        cout << (IsPossiblePartition(nums) ? "True" : "False") << endl;
    }

}

