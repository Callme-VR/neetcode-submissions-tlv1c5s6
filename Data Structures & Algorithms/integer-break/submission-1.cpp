class Solution {
   public:
    int integerBreak(int n) {
        // dp[i] = max product from splitting i into at least 2 positive integers
        vector<int> dp(n + 1, 0);

        dp[1] = 1;  // base value; 1 can't be split, so it only counts as a whole part
        dp[2] = 1;  // 2 = 1 + 1 -> 1 * 1 = 1

        // build the answer bottom-up for every sum i from 3 to n
        for (int i = 3; i <= n; i++) {
            // j = first part of the split; the rest is (i - j)
            // j <= i/2 is enough because (j, i-j) and (i-j, j) give the same product
            for (int j = 1; j <= i / 2; j++) {
                // option 1: split into exactly j and (i-j), keeping (i-j) whole
                int wholesplit = j * (i - j);

                // option 2: take j, then split (i-j) further using its best product dp[i-j]
                int splitkeep = j * dp[i - j];

                // keep the best value seen across all choices of j
                dp[i] = max(dp[i], max(wholesplit, splitkeep));
            }
        }
        // best product for the full number n
        return dp[n];
    }
};