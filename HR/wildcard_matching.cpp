class Solution {
public:
    // Recursive + memoization
    // Time O(nm)  Space O(nm)
    map<pair<int, int>, bool> memo;
    bool recur(string& s, string& p, int sidx, int pidx) {
        //cout << sidx << " " << pidx << endl;
        pair<int, int> sp = make_pair(sidx, pidx);
        if (memo.find(sp) != memo.end()) return memo[sp];
        if (sidx == s.size() && pidx == p.size()) {
            memo[sp] = true;
            return true;
        } else if (sidx == s.size() && pidx < p.size()) {
            if (p[pidx] == '*') {
                memo[sp] = recur(s, p, sidx, pidx + 1);
            } else {
                memo[sp] = false;
            }
            return memo[sp];
        } else if (pidx == p.size() && sidx < s.size()) {
            memo[sp] = false;
            return memo[sp];
        }

        if (p[pidx] == '?' || p[pidx] == s[sidx]) {
            memo[sp] = recur(s, p, sidx + 1, pidx + 1);
        } else if (p[pidx] == '*') {
            memo[sp] = recur(s, p, sidx + 1, pidx) || recur(s, p, sidx, pidx + 1) || recur(s, p, sidx + 1, pidx + 1);
        } else {
            memo[sp] = false;
        }
        return memo[sp];
    }
    bool isMatch(string s, string p) {
        return recur(s, p, 0, 0);
    }

    // Bottom-up DP
    // Time O(nm)  Space O(nm)
    bool isMatch(string s, string p) {
        int ssize = s.size(), psize = p.size();
        vector<vector<bool>> dp(ssize + 1, vector<bool>(psize + 1, false));
        dp[ssize][psize] = true;
        for (int sidx = ssize; sidx >= 0; sidx--) {
            for (int pidx = psize - 1; pidx >= 0; pidx--) {
                if ('*' == p[pidx]) {
                    if (sidx == ssize && pidx == psize - 1) {
                        dp[sidx][pidx] = true;
                    } else if (sidx < ssize) {
                        dp[sidx][pidx] = dp[sidx][pidx] || dp[sidx + 1][pidx + 1] || dp[sidx + 1][pidx];
                    }
                    dp[sidx][pidx] = dp[sidx][pidx] || dp[sidx][pidx + 1];
                } else if (sidx < ssize && (s[sidx] == p[pidx] || '?' == p[pidx])) {
                    dp[sidx][pidx] = dp[sidx + 1][pidx + 1];
                }
            }
        }
        return dp[0][0];
    }
};
