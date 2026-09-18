
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool canPartition(vector<int>& nums) {

        // Calculate the total sum of all elements
        int totalSum = 0;

        for (int num : nums) {
            totalSum += num;
        }

        // If total sum is odd, we cannot divide it
        // into two equal subsets
        if (totalSum % 2 != 0) {
            return false;
        }

        // Each subset should have half of the total sum
        int target = totalSum / 2;

        // dp[sum] = true if we can make this sum
        vector<bool> dp(target + 1, false);

        // Sum 0 is always possible by choosing nothing
        dp[0] = true;

        // Process every number
        for (int num : nums) {

            // Traverse backwards because each number
            // can be used only once
            for (int sum = target; sum >= num; sum--) {

                // Don't take num:
                // dp[sum] remains unchanged
                //
                // Take num:
                // check whether sum - num was possible
                dp[sum] = dp[sum] || dp[sum - num];
            }
        }

        // If target can be formed,
        // equal partition is possible
        return dp[target];
    }
};
