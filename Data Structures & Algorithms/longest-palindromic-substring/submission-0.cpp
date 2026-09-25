class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        // dp[i][j] = true if substring s[i...j]
        // is a palindrome.
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int start = 0;
        int maxlenght = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;

                    // .calculate the current lenght

                    int currentlenght = j - i + 1;

                    if (currentlenght > maxlenght) {
                        maxlenght = currentlenght;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxlenght);
    }
};