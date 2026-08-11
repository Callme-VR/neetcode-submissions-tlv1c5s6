class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long l = 1;
        long long result = *max_element(piles.begin(), piles.end());
        long long final_result = result;

        while (l <= result) {
            long long mid = l + (result - l) / 2;
            long long total_time = 0;

            for (int p : piles) {
                // Equivalent to ceil(p / mid) using integer arithmetic
                total_time += (p + mid - 1) / mid;
            }

            if (total_time <= h) {
                final_result = mid;   // Save valid speed
                result = mid - 1;     // Try to find a smaller speed on the left
            } else {
                l = mid + 1;          // Too slow, need a higher speed on the right
            }
        }
        
        return final_result;
    }
};