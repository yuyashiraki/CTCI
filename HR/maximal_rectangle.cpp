class Solution {
public:
    // Using Stack
    // Time O(nm)  Space O(m)
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (!n) return 0;
        int m = matrix[0].size(), maxarea = 0;
        vector<int> heights(m, 0);
        for (int y = 0; y < n; y++) {
            stack<int> stk;
            stk.push(-1);
            for (int x = 0; x <= m; x++) {
                if (m > x) {
                    if (matrix[y][x] == '1') {
                        heights[x]++;
                    } else {
                        heights[x] = 0;
                    }
                }
                //cout << " " << heights[x] << endl;
                while (stk.top() != -1 && (x == m || heights[stk.top()] >= heights[x])) {
                    int h = heights[stk.top()];
                    stk.pop();
                    maxarea = max(maxarea, h * (x - stk.top() - 1));
                }
                stk.push(x);
            }
            //cout << endl;
        }
        return maxarea;
    }
};
