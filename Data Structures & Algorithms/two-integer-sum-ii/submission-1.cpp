class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;

        while (i < j) {
            int currentSum = nums[i] + nums[j];

            if (currentSum > target) j--;
            else if (currentSum < target) i++;
            else return {i + 1, j + 1}; // 1-based index
        }
        return {};
    }
};