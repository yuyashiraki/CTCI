class Solution {
public:
    // Recursive
    // Time O((T+P)2^(T + P/2)) where T=s.size(), P=p.size()
    // Space O(2^(T + P/2)) in below method
    bool isMatch(string s, string p) {
        if (p.size() == 0)
            return s.size() == 0;
        bool match = s.size() && (p.at(0) == s.at(0) || p.at(0) == '.');
        if (p.size() > 1 && p.at(1) == '*') {
            return isMatch(s, p.substr(2, p.size() - 2))
                || (match && isMatch(s.substr(1, s.size() - 1), p));
        } else {
            return match && isMatch(s.substr(1, s.size() - 1), p.substr(1, p.size() - 1));
        }
    }

    // DP: Time O(T*P)  Space O(T*P)
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[s.size()][p.size()] = true;
        for (int i = s.size(); i >= 0; i--) {
            for (int j = p.size() - 1; j >= 0; j--) {
                bool match = i < s.size() &&
                            (p.at(j) == s.at(i) ||
                            p.at(j) == '.');
                if (j + 1 < p.size() && p.at(j + 1) == '*') {
                    dp[i][j] = dp[i][j + 2] || match && dp[i+1][j];
                } else {
                    dp[i][j] = match && dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }
};
