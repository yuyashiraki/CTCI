class KthLargest {
public:
    // using Priority Queue
    // Time O(n*log(k)) Space O(k)
    priority_queue<int,vector<int>, greater<int>> PQ;
    int K;
    KthLargest(int k, vector<int> nums) {
        K = k;
        for (int i = 0; i < nums.size(); i++) {
            if (PQ.size() < K) PQ.push(nums[i]);
            else {
                if (PQ.top() < nums[i]) {
                    PQ.pop();
                    PQ.push(nums[i]);
                }
            }
        }
    }

    int add(int val) {
        if (PQ.size() < K) PQ.push(val);
        else {
            if (PQ.top() < val) {
                PQ.pop();
                PQ.push(val);
            }
        }
        return PQ.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
