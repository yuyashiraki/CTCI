class Solution {
public:
    // using Sort
    // Time O(nlog(n))  Space O(1)
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }

    // using priority queue
    // Time O(nlog(k))  Space O(k)
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> PQ;
        for (int i = 0; i < nums.size(); i++) {
            PQ.push(nums[i]);
            if (PQ.size() > k) {
                PQ.pop();
            }
        }
        return PQ.top();
    }

    // using QuickSort
    // Time O(n^k)  Space O(1)
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        while (1) {
            //cout << l << " " << r << endl;
            int pivot = nums[l];
            int il = l++, ir = r;
            while (l <= r) {
                if (nums[l] <= pivot && pivot < nums[r]) {
                    swap(nums[l], nums[r]);
                }
                if (nums[l] > pivot) l++;
                if (nums[r] <= pivot) r--;
            }
            swap(nums[il], nums[r]);
            if (k - 1 == r) {
                return nums[r];
            } else if (r < k - 1) {
                l = r + 1, r = ir;
            } else {
                l = il, r = r - 1;
            }
        }
        return INT_MAX;
    }};
