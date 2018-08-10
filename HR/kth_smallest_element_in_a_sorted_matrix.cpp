class Solution {
public:
    // Priority Queue
    // Time O(klog(n))  Space O(n)
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        if (!n) return 0;
        int m = matrix[0].size(), i;
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> PQ;
        for (i = 0; i < n; i++) {
            PQ.emplace(matrix[i][0], i, 0);
        }
        int ans = 0;
        for (i = 0; i < k; i++) {
            if (PQ.empty()) return 0;
            ans = get<0>(PQ.top());
            int y = get<1>(PQ.top()), x = get<2>(PQ.top());
            PQ.pop();
            if (x + 1 < m) {
                PQ.emplace(matrix[y][x+1], y, x+1);
            }
        }
        return ans;
    }

    // Range-based Binary Search
    // Time O(l)
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        if (!n) return 0;
        int m = matrix[0].size(), i;
        int lo = matrix[0][0], hi = matrix[n-1][m-1] + 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int pos = 0;
            for (i = 0; i < n; i++) {
                pos += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            //cout << pos << endl;
            if (pos < k) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};
