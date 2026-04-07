class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>store;
        vector<int>Result;

        for(int i=0;i<nums.size();i++){
            if(!store.empty() && store.front()==i-k){
                store.pop_front();
            }
            while(!store.empty() && nums[store.back()]<nums[i]){
                store.pop_back();
            }
            store.push_back(i);

            if(i>=k-1){
                Result.push_back(nums[store.front()]);
            }
        }
        return Result;
        
    }
};