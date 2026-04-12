class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int midelement=low+(high-low)/2;

            if(nums[midelement]==target) return midelement;

            if(nums[midelement]>=nums[low]){
                if(target>=nums[low] && target<nums[midelement]){
                    high=midelement-1;
                }
                else{
                    low=midelement+1;
                }
            }
            else{
                if(target>nums[midelement] && target<=nums[high]){
                    low=midelement+1;
                }
                else {
                    high=midelement-1;
                }
            }
        }
        return -1;
    }
};
