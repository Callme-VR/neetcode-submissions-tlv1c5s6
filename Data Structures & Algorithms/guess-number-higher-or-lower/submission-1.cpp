class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int res = guess(mid);

            if (res == 0) {
                return mid;
            }
            else if (res == -1) {
                // Your guess was too high, move the ceiling down
                high = mid - 1; 
            }
            else {
                // Your guess was too low, move the floor up
                low = mid + 1;
            }
        }
        return -1;
    }
};