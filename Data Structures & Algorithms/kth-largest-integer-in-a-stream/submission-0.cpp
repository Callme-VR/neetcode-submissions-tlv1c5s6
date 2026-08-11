class KthLargest {
   private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    long long k;

   public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (long long num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }

    long long add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};
