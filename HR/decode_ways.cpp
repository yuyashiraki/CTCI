class Solution {
public:
    // Recursion
    // Time O(2^n)  Space O(n)
    // Recursion + Memo
    // Time O(n)  Space O(n)
    unordered_map<int, int> MEMO;
    int numDecodings(string s, int pos) {
        if (MEMO.count(pos)) {
            return MEMO[pos];
        }
        if (pos == s.size()) {
            return 1;
        }
        int ans = 0;
        if (pos < s.size() - 1 && ('1' == s[pos] || ('2' == s[pos] && s[pos+1] < '7'))) {
            ans += numDecodings(s, pos + 2);
        }
        if ('0' != s[pos]) ans += numDecodings(s, pos + 1);
        MEMO[pos] = ans;
        return ans;
    }
    int numDecodings(string s) {
        return numDecodings(s, 0);
    }

    // DP
    // Time O(n)  Space O(1)
    int numDecodings(string s) {
        int cur = 1, next = 0, next2 = 0;
        for (int pos = 0; pos < s.size(); pos++) {
            if (pos < s.size() - 1 && ('1' == s[pos] || '2' == s[pos] && s[pos+1] < '7')) next2 += cur;
            if ('0' != s[pos]) next += cur;
            cur = next; next = next2; next2 = 0;
        }
        return cur;
    }
};
