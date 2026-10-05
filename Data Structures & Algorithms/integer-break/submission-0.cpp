class Solution {
   public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);

        dp[1] = 1;
        dp[2] = 1;

        for (int i = 3; i <= n; i++) {
            // try for every possible way
            for (int j = 1; j <= i / 2; j++) {
                //   // split into exactly j and (i-j)

                int wholesplit = j * (i - j);
                int splitkeep = j * dp[i - j];

                dp[i] = max(dp[i], max(wholesplit, splitkeep));
            }
        }
        return dp[n];
    }
};