class Solution {
public:
    // Using Set
    // Time O(2n)  Space O(n)
    int recur(unordered_set<int>& st, int i, int direction) {
        auto itr = st.find(i);
        if (itr == st.end()) return 0;
        st.erase(itr);
        return 1 + recur(st, i + direction, direction);
    }
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }
        int ans = 0;
        while (!st.empty()) {
            auto itr = st.begin();
            int i = *itr;
            st.erase(itr);
            ans = max(ans, 1 + recur(st, i - 1, -1) + recur(st, i + 1, 1));
        }
        return ans;
    }
};
