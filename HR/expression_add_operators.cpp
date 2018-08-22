class Solution {
public:
    // DFS
    // Time O(4^n)  Space O(n)
    void dfs(vector<string> &ans, const string &num, const int &target, string cand, int idx, int cum, int tmp) {
        //cout << cand << " index:" << idx << endl;
        char last_op;
        if (idx == 0) last_op = '+';
        else last_op = *(cand.rbegin());
        for (int i = idx + 1; i <= num.size(); i++) {
            string t = num.substr(idx, i - idx);
            long tnum = stol(t);
            if (to_string(tnum).size() != t.size()) continue;
            switch (last_op) {
                case '+':
                    if (i == num.size()) {
                        if (cum + tnum == target) ans.push_back(cand + t);
                    } else {
                        dfs(ans, num, target, cand + t + "+", i, cum + tnum, 0);
                        dfs(ans, num, target, cand + t + "-", i, cum + tnum, 0);
                        dfs(ans, num, target, cand + t + "*", i, cum, tnum);
                    }
                    break;
                case '-':
                    if (i == num.size()) {
                        if (cum - tnum == target) ans.push_back(cand + t);
                    } else {
                        dfs(ans, num, target, cand + t + "+", i, cum - tnum, 0);
                        dfs(ans, num, target, cand + t + "-", i, cum - tnum, 0);
                        dfs(ans, num, target, cand + t + "*", i, cum, -tnum);
                    }
                    break;
                case '*':
                    if (i == num.size()) {
                        if (cum + tmp * tnum == target) ans.push_back(cand + t);
                    } else {
                        dfs(ans, num, target, cand + t + "+", i, cum + tmp * tnum, 0);
                        dfs(ans, num, target, cand + t + "-", i, cum + tmp * tnum, 0);
                        dfs(ans, num, target, cand + t + "*", i, cum, tmp * tnum);
                    }
                    break;
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        dfs(ans, num, target, "", 0, 0, 0);
        return ans;
    }

};
