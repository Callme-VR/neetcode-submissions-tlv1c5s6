class Solution {
public:

    // Solve the normal House Robber problem
    // for houses from 'start' to 'end'.
    int robrange(vector<int>& nums, int start, int end) {

        // If there is only one house in the range,
        // simply return the money in that house.
        if (start == end) {
            return nums[start];
        }

        // dp[i] = maximum money we can rob
        // from the 'start' house up to the current house.
        vector<int> dp(end - start + 1);

        // Base case:
        // If we consider only the first house,
        // the maximum money is its own value.
        dp[0] = nums[start];

        // For the first two houses, we can rob
        // only the house with more money.
        dp[1] = max(nums[start], nums[start + 1]);

        // Build the DP table from left to right.
        for (int i = 2; i < dp.size(); i++) {

            // Convert the DP index 'i'
            // into the actual index of nums.
            int currenthouse = start + i;

            // Option 1: Skip the current house.
            // The answer remains the same as the previous house.
            int skip = dp[i - 1];

            // Option 2: Rob the current house.
            // Since adjacent houses cannot be robbed,
            // add its money to the answer from two houses before.
            int rob = nums[currenthouse] + dp[i - 2];

            // Choose the option that gives more money.
            dp[i] = max(skip, rob);
        }

        // The last DP value contains the maximum
        // money that can be robbed in this range.
        return dp.back();
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        // If there is only one house,
        // simply rob that house.
        if (n == 1) {
            return nums[0];
        }

        // Since the houses are arranged in a circle,
        // the first and last houses are adjacent.
        //
        // Therefore, we have two possible cases:
        //
        // Case 1:
        // Rob houses from index 0 to n-2.
        // This excludes the last house.
        int case1 = robrange(nums, 0, n - 2);

        // Case 2:
        // Rob houses from index 1 to n-1.
        // This excludes the first house.
        int case2 = robrange(nums, 1, n - 1);

        // Take the maximum of the two cases.
        return max(case1, case2);
    }
};