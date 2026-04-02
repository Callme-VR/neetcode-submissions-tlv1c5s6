class Solution {
public:
    int maxArea(vector<int>& height) {
        long long l = 0;
        long long r = height.size() - 1;
        long long store = 0;

        while (l < r) {
            long long area = min(height[l], height[r]) * (r - l);
            store = max(store, area);

            if(height[l]<=height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return store;
    }
};