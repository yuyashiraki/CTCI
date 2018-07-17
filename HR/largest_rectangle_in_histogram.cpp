class Solution {
public:
    // Using Stack
    // Time O(n)  Space O(n)
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        stk.push(-1);
        int maxarea = 0, n = heights.size();
        for (int i = 0; i <= n; ++i) {
            while (stack.top() != -1 && (heights[stack.top()] >= heights[i] || i == n)) {
                int h = heights[stack.top()];
                stack.pop();
                maxarea = max(maxarea, h * (i - 1 - stack.top()));
            }
            if (i < n) stack.push(i);
        }
        return maxarea;
    }


    // Divide and Conquer
    // Avg.Time O(nlog(n)) Wrst.Time O(n^2)  Space O(n)
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), maxarea = 0;
        queue<pair<int, int>> qq;
        qq.emplace(0, n);
        while (!qq.empty()) {
            int l = qq.front().first, r = qq.front().second, minh = INT_MAX, minpos = 0;
            qq.pop();
            if (r <= l) continue;
            for (int cur = l; cur < r; cur++) {
                if (minh > heights[cur]) {
                    minh = heights[cur];
                    minpos = cur;
                }
            }
            maxarea = max(minh * (r - l), maxarea);
            qq.emplace(l, minpos);
            qq.emplace(minpos + 1, r);
        }
        return maxarea;
    }

    // Brute Force
    // Time O(n^2) Space O(1)
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), maxarea = 0;
        for (int i = 0; i < n; i++) {
            int minh = INT_MAX;
            for (int j = i; j < n; j++) {
                minh = min(minh, heights[j]);
                maxarea = max(minh * (j - i + 1), maxarea);
            }
        }
        return maxarea;
    }
};
