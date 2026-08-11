class Solution {
public:
    long long findInMountainArray(long long target, MountainArray &mountainArr) {
        long long n = mountainArr.length();

        // 1. Find the peak index
        long long l = 1;
        long long r = n - 2;
        long long peak = 0;

        while (l <= r) {
            long long m = l + (r - l) / 2;
            long long left = mountainArr.get(m - 1);
            long long mid = mountainArr.get(m);
            long long right = mountainArr.get(m + 1);

            if (left < mid && mid < right) {
                l = m + 1;
            } else if (left > mid && mid > right) {
                r = m - 1;
            } else {
                peak = m;
                break;
            }
        }

        // 2. Search in the strict increasing left part [0, peak]
        l = 0;
        r = peak;
        while (l <= r) {
            long long m = l + (r - l) / 2;
            long long val = mountainArr.get(m);
            if (val < target) {
                l = m + 1;
            } else if (val > target) {
                r = m - 1;
            } else {
                return m;
            }
        }

        // 3. Search in the strict decreasing right part [peak + 1, n - 1]
        l = peak + 1;
        r = n - 1;
        while (l <= r) {
            long long m = l + (r - l) / 2;
            long long val = mountainArr.get(m);
            if (val > target) { // Decreasing array logic
                l = m + 1;
            } else if (val < target) {
                r = m - 1;
            } else {
                return m;
            }
        }

        return -1;
    }
};