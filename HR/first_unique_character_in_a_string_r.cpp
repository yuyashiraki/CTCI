class Solution {
public:
    // using Table to counter
    // Time O(n)  Space O(n)
    int firstUniqChar(string s) {
        vector<vector<int>> counter(26);
        for (int i = 0; i < s.size(); i++) {
            counter[s[i] - 'a'].push_back(i);
        }
        int ans = s.size();
        for (int i = 0; i < 26; i++) {
            if (1 == counter[i].size()) ans = min(ans, counter[i][0]);
        }
        return ans == s.size() ? -1 : ans;
    }
};
