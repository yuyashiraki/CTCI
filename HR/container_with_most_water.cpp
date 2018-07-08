class Solution {
public:
    // Brute Force
    // Time O(n^2)  Space O(1)
    int maxArea(vector<int>& height) {
        int n = height.size(), ans = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                ans = max(ans, (j - i) * min(height[i], height[j]));
            }
        }
        return ans;
    }

    // Two pointers
    // Time O(n)  Space O(1)
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, ans = 0;
        while (l < r) {
            ans = max(ans, (r - l) * min(height[l], height[r]));
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }

    // Two pointers + sorting
    // Time O(nlog(n))  Space O(1)
    int maxArea(vector<int>& height) {
        vector<pair<int, int>> heidx;
        int i, l, r, n = height.size(), ans = 0;
        for (i = 0; i < n; i++) {
            heidx.push_back(make_pair(height[i],i));
        }
        sort(heidx.begin(), heidx.end(), greater<pair<int, int>>());
        l = r = heidx[0].second;
        for (i = 1; i < n; i++) {
            int tmpidx = heidx[i].second;
            l = min(l, tmpidx);
            r = max(r, tmpidx);
            ans = max(ans, (r - l) * min(height[l], height[r]));
        }
        return ans;
    }
};
