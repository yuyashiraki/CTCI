class Solution {
public:
    // Greedy with two pointers
    // Time O(n)  Space O(n)
    vector<int> partitionLabels(string S) {
        vector<int> ans;
        if (S.size() == 0) return ans;
        vector<int> last(26, -1);
        for (int i = 0; i < S.size(); i++) last[S[i] - 'a'] = i;
        int j = 0, anchor = 0;
        for (int i = 0; i < S.size(); i++) {
            j = max(j, last[S[i] - 'a']);
            if (i == j) {
                ans.push_back(i - anchor + 1);
                anchor = i + 1;
            }
        }
        return ans;
    }
};
