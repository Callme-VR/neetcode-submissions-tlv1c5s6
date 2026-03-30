class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>Hash_map;
        int result=0;

        for (auto num:nums){
            if(!Hash_map[num]){
                Hash_map[num]=Hash_map[num-1]+Hash_map[num+1] + 1;
                Hash_map[num-Hash_map[num-1]]=Hash_map[num];
                Hash_map[num+Hash_map[num+1]]=Hash_map[num];
                result=max(result,Hash_map[num]);
            }
        }
        return result;
    }
};
