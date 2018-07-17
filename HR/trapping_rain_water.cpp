class Solution {
public:
    // two pointers solution
    // Time O(n) Space O(1)
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1, lmax = 0, rmax = 0, ans = 0;
        while (l <= r) {
            if (height[l] <= height[r]) {
                if (lmax <= height[l]) {
                    lmax = height[l];
                } else {
                    ans += lmax - height[l];
                }
                l++;
            } else {
                if (rmax <= height[r]) {
                    rmax = height[r];
                } else {
                    ans += rmax - height[r];
                }
                r--;
            }
        }
        return ans;
    }

    //2-pass solution
    // Time O(2n)  Space O(n)
    int trap(vector<int>& height) {
        int i, n = height.size(), m = 0, ans = 0;
        vector<int> line(n, 0);
        for (i = 0; i < n; i++) {
            m = max(height[i], m);
            line[i] = m;
        }
        m = 0;
        for (i = n - 1; i >= 0; i--) {
            m = max(height[i], m);
            line[i] = min(m, line[i]);
            ans += line[i] - height[i];
        }
        return ans;
    }
};
