class Solution {
public:
    // Brute force
    // Time: O(n^3)  Memory: O(1)
    string longestPalindrome(string s)
    {
        string longest = "";
        for (int i = 0; i < s.size() - longest.size(); i++) {
            for (int j = i + longest.size(); j < s.size(); j++) {
                int l = i, r = j;
                bool flg = true;
                while (l <= r) {
                    if (s[l] != s[r]) {
                        flg = false;
                        break;
                    }
                    l++; r--;
                }
                if (flg) longest = s.substr(i, j - i + 1);
            }
        }
        return longest;
    }

    // DP
    // Time: O(n^2)  Memory: O(n^2)
    string longestPalindrome(string s)
    {
        int len = s.size();
        int longest_idx = 0, longest_len = 1;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        // palindrome len = 1
        for (int i = 0; i < len; i++) {
            dp[i][i] = true;
        }
        // palindrome len = 2
        for (int i = 1; i < len; i++) {
            if (s[i] == s[i - 1]) {
                dp[i - 1][i] = true;
                if (2 > longest_len) {
                    longest_len = 2;
                    longest_idx = i - 1;
                }
            }
        }
        // palindrome len = 3,4,5,...
        int cnt = 2;
        while (cnt + 1 <= s.size()) {
            for (int i = 0, j = i + cnt; j < s.size(); i++, j++) {
                if (dp[i + 1][j - 1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    if (longest_len < j - i + 1) {
                        longest_len = j - i + 1;
                        longest_idx = i;
                    }
                }
            }
            cnt++;
        }
        return s.substr(longest_idx, longest_len);
    }

    // Expanding around center
    // Time: O(n^2)  Memory: O(1)
    string longestPalindrome(string s)
    {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            int len1 = expandAroundCenters(s, i, i);
            int len2 = expandAroundCenters(s, i, i + 1);
            int len = max(len1, len2);
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
    int expandAroundCenters(string s, int left, int right)
    {
        int L = left, R = right;
        while (L >= 0 && R < s.size() && s.at(L) == s.at(R)) {
            L--;
            R++;
        }
        return R - L - 1;
    }
};
