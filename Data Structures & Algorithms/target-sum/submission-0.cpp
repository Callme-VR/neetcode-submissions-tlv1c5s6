
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;

        for (int num : nums) {
            total += num;
        }

        // Target cannot exceed the total sum.
        if (abs(target) > total) {
            return 0;
        }

        // The subset sum must be an integer.
        if ((total + target) % 2 != 0) {
            return 0;
        }

        int subsetSum = (total + target) / 2;

        // dp[i][j] = ways to make sum j using first i elements.
        vector<vector<int>> dp(
            n + 1, vector<int>(subsetSum + 1, 0)
        );

        // One way to make sum 0: choose no elements.
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= subsetSum; j++) {

                // Do not take the current element.
                dp[i][j] = dp[i - 1][j];

                // Take the current element if possible.
                if (j >= nums[i - 1]) {
                    dp[i][j] +=
                        dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[n][subsetSum];
    }
};
