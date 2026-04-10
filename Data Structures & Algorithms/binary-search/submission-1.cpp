class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            // Standard way to prevent potential overflow
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid; // Target found!
            } 
            else if (nums[mid] > target) {
                high = mid - 1; // Search the left half
            } 
            else {
                low = mid + 1; // Search the right half
            }
        }

        return -1; // Target not found after checking entire range
    }
};