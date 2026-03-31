class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        std::rotate(nums.begin(),nums.end()-(k%n),nums.end());
    }
};