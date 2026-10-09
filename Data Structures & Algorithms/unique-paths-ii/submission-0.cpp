
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // If the starting cell is blocked, no path exists.
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        // Create an m x n DP table initialized with 0.
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // One way to reach the starting cell.
        dp[0][0] = 1;

        // Traverse each cell in the grid.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // The starting cell is already initialized.
                if (i == 0 && j == 0) {
                    continue;
                }

                // An obstacle cannot be entered.
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }

                // Add the number of paths from above.
                if (i > 0) {
                    dp[i][j] += dp[i - 1][j];
                }

                // Add the number of paths from the left.
                if (j > 0) {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }

        // Return the number of paths to the destination.
        return dp[m - 1][n - 1];
    }
};