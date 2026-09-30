class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        vector<bool> dp(n + 1, 0);
        // for the i index of string is segment from the start
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            // try everypossible ch from the last

            for (int j = 0; j < i; j++) {
                if (dp[j]) {
                    // extract the ch from string

                    string word = s.substr(j, i - j);

                    // and alsoo check the substring is exits in the dictionary
                    if (wordSet.count(word)) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};
