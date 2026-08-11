

class Solution {
   public:
    long long findInMountainArray(long long target, MountainArray& mountainArr) {
        long long n = mountainArr.length();

        for (long long i = 0; i < n; i++) {
            if (mountainArr.get(i) == target) {
                return i;
            }
        }

        return -1;
    }
};