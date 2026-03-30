class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int>indexToReturn;

       for(int i=0;i<nums.size();i++){
        indexToReturn[nums[i]]=i;
       } 

       for(int i=0;i<nums.size();i++){
        int diff=target - nums[i]; //complement of current element
        if(indexToReturn.count(diff)&& indexToReturn[diff]!=i ){
            return {i,indexToReturn[diff]};
        }
       }
       return {};
    }
};
