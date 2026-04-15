class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        // low is the max element, high is the sum of all elements
        int low = *max_element(nums.begin(), nums.end());
        
        // Use long long for sum to avoid overflow if constraints were larger, 
        // though int works for these specific constraints (10^9).
        int high = accumulate(nums.begin(), nums.end(), 0);

        int result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canSplit(nums, k, mid)) {
                result = mid;
                high = mid - 1; // Try to find a smaller valid "largest sum"
            } else {
                low = mid + 1; // Current mid is too small, need a larger limit
            }
        }
        return result;
    }

private:
    bool canSplit(vector<int>& nums, int k, int largest) {
        int subarray = 1;
        int currentsum = 0;

        for (int num : nums) {
            currentsum += num;
            // If adding the current number exceeds our 'largest' limit
            if (currentsum > largest) { 
                subarray++;       // Start a new subarray
                currentsum = num; // This number starts the new sum
                
                if (subarray > k) return false;
            }
        }
        return true; // Added missing semicolon
    }
};