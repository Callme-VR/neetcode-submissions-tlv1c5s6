class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;

        while(low<=high){
            int midElement=low+(high-low)/2;

            if(nums[midElement]==target) {
                return midElement;
            }
            else if(nums[midElement]<target){
                low=midElement+1;
            }
            else{
                high=midElement-1;
            }
        }
        return low;
    }
};