class Solution {
public:
    // Backtracking
    // Time O(2^(2n)) = O(4^n)   Space O(2n) = O(n)
    void recur(vector<string>& ans, string cur, int l, int r) {
        //cout << cur << " " << l << " " << r << endl;
        if (!l && !r) {
            ans.push_back(cur);
        }
        if (l > 0) {
            recur(ans, cur + "(", l - 1, r);
        }
        if (r > l) {
            recur(ans, cur + ")", l, r - 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        recur(ans, "", n, n);
        return ans;
    }

    // Divide and Conquer
    map<int, vector<string>> mp;
    vector<string> generateParenthesis(int n) {
        if (mp.find(n) != mp.end()) return mp[n];
        vector<string> ans;
        if (0 == n) {
            ans.add("");
        } else {
            for (int c = 0; c < n; ++c) {
                vector<string> left = generateParenthesis(c);
                for (int i = 0; i < left.size(); i++) {
                    vector<string> right = generateParenthesis(n - 1 - c);
                    for (int j = 0; j < right.size(); j++) {
                        ans.push_back("(" + left[i] + ")" + right[j]);
                    }
                }
            }
        }
        mp[n] = ans;
        return ans;
    }

};
