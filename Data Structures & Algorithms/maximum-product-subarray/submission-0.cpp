class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        vector<int> maxdp(n), mindp(n);

        // Base case
        maxdp[0] = mindp[0] = nums[0];

        int result = nums[0];

        // Run the loop from index 1
        for (int i = 1; i < n; i++) {

            int a = nums[i] * maxdp[i - 1];
            int b = nums[i] * mindp[i - 1];

            // Current maximum product
            maxdp[i] = max({nums[i], a, b});

            // Current minimum product
            mindp[i] = min({nums[i], a, b});

            // Update the overall maximum result
            result = max(result, maxdp[i]);
        }

        return result;
    }
};