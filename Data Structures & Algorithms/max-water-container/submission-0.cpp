class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int store = 0;

        while (l < r) {
            int area = min(heights[l], heights[r]) * (r - l);
            store = max(store, area);

            if (heights[l] <= heights[r]) {
                l++;
                
            } else {
                r--;
            }
        }
        return store;
    }
};