class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0;
        int j=nums.size()-1;

        while(i<j){
            int currentsum=nums[i]+nums[j];

            if(currentsum>target) j--;
            else if(currentsum<target) i++;
            else if(currentsum==target) return {i+1,j+1};
        }
        return {};
    }
};
