class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        int n = s.length();

        // Store all dictionary words in a set
        // so we can check whether a word exists quickly.
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        // dp[i] = true means the first i characters
        // of the string can be segmented.
        vector<bool> dp(n + 1, false);

        // Empty string can always be segmented.
        dp[0] = true;

        // Try to determine dp[i] for every position.
        for (int i = 1; i <= n; i++) {

            // Try every possible starting position j
            // for the last word.
            for (int j = 0; j < i; j++) {

                // If the first j characters are already
                // successfully segmented...
                if (dp[j]) {

                    // Extract the substring from j to i-1.
                    string word = s.substr(j, i - j);

                    // Check whether this substring exists
                    // in the dictionary.
                    if (wordSet.count(word)) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        // dp[n] tells us whether the complete string
        // can be segmented.
        return dp[n];
    }
};