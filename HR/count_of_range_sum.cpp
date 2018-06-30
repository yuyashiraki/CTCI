class Solution {
public:
    // Divide and Conquer
    // Time: O(nlog(n))  Memory: O(n) for sum[]
    int mergeSort(vector<long>& sum, int lower, int upper, int low, int high)
    {
        if (high - low <= 1) return 0;
        int mid = (low + high) / 2, m = mid, n = mid, count = 0;
        count = mergeSort(sum, lower, upper, low, mid) + mergeSort(sum, lower, upper, mid, high);
        for (int i = low; i < mid; i++) {
            while (m < high && sum[m] - sum[i] < lower) m++;
            while (n < high && sum[n] - sum[i] <= upper) n++;
            count += n - m;
        }
        inplace_merge(sum.begin() + low, sum.begin() + mid, sum.begin() + high);
        return count;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper)
    {
        int len = nums.size();
        vector<long> sum(len + 1, 0);
        for (int i = 0; i < len; i++) sum[i+1] = sum[i] + nums[i];
        return mergeSort(sum, lower, upper, 0, len + 1);
    }

    // Balanced tree
    // Time: O(nlog(n)) without distance  Memory: O(n)
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        multiset<long long> pSum;
        int res = 0, i;
        long long left, right, sum = 0;
        for (i = 0. pSum.insert(0); i < nums.size(); ++i) {
            sum += nums[i];
            res += distance(pSum.lower_bound(sum - upper), pSum.upper_bound(sum - lower));
            pSum.insert(sum);
        }
        return res;
    }

    // Brute force
    // Time: O(n^2)
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> sums(nums.size(), 0);
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            sums[i] = sum;
        }
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                long long r = sums[j], l = i ? sums[i-1] : 0;
                long long range_sum = r - l;
                if (range_sum <= upper && range_sum >= lower) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
