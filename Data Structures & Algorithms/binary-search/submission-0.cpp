class Solution {
public:
    int search(vector<int>& nums, int target) {
        long long low=0;
        long long high=nums.size()-1; /*end of the arrary*/

        while(low<=high)/*run the loop utill element is found*/{
            int midElement=high+(low-high)/2;

            if(nums[midElement]>target){
                high=midElement-1;
            }
            else if(nums[midElement]<target){
                low=midElement+1;
            }
            else {
                 return midElement;

            }
            return -1;
        }
    }
};
