class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        // Create a frequency array for 26 possible tasks: A to Z.
        vector<int> freq(26, 0);

        // Count how many times each task appears.
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        // Find the frequency of the most frequent task.
        int maxfreq = 0;

        for (int f : freq) {
            maxfreq = max(maxfreq, f);
        }

        // Count how many different tasks have the same maximum frequency.
        // This is important when multiple tasks share the highest frequency.
        int countMax = 0;

        for (int f : freq) {
            if (f == maxfreq) {
                countMax++;
            }
        }

        // The most frequent task creates the basic scheduling structure.
        //
        // (maxfreq - 1) = number of gaps between occurrences
        // (n + 1)       = size of each gap including the task itself
        // countMax      = number of tasks occupying the final position
        //
        // Example:
        // A A A, n = 2
        // A _ _ A _ _ A
        //
        // Required intervals = (3 - 1) * (2 + 1) + 1 = 7

        int result = (maxfreq - 1) * (n + 1) + countMax;

        // If there are enough different tasks to fill all idle positions,
        // we don't need any idle time.
        //
        // Therefore, the answer cannot be smaller than the total
        // number of tasks.
        return max((int)tasks.size(), result);
    }
};