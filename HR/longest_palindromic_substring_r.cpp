class Solution {
public:
    // DP
    // Time O(n^2)  Space O(n^2)
    string longestPalindrome(string s) {
        vector<vector<bool>> DP(s.size(), vector<bool>(s.size(), false));
        string ans = "";
        for (int len = 0; len < s.size(); len++) {
            if ((int)ans.size() < len - 1) return ans;
            for (int j = 0; j < s.size() - len; j++) {
                if (len == 0) {
                    DP[j][j] = true;
                    if (ans.size() <= len) ans = s.substr(j, len + 1);
                } else if (len == 1) {
                    if (s[j] == s[j+1]) {
                        DP[j][j+1] = true;
                        if (ans.size() <= len) ans = s.substr(j, len + 1);
                    }
                } else {
                    if (DP[j + 1][j + len - 1] && s[j] == s[j + len]) {
                        DP[j][j+len] = true;
                        if (ans.size() <= len) ans = s.substr(j, len + 1);
                    }
                }
            }
        }
        return ans;
    }
};
