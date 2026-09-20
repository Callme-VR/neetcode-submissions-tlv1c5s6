class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

        // dp[i] = minimum cost required to reach step i
        vector<int> dp(n);

        // Base cases
        dp[0] = cost[0];
        dp[1] = cost[1];

        // Build the DP table
        for (int i = 2; i < n; i++) {

            // We can reach i from either:
            // i-1 or i-2
            //
            // Choose the cheaper path
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }

        // We can reach the top from either
        // the last step or the second-last step
        return min(dp[n - 1], dp[n - 2]);
    }
};