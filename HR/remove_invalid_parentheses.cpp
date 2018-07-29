class Solution {
public:
    // DFS, avoiding duplicates by keeping the last modified position
    // Time O(kn^2)  Space O(k) where k = #answers
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        remove(s, ans, 0, 0, '(', ')');
        return ans;
    }
    void remove(string s, vector<string>& ans, int iStart, int jStart, char openParen, char closeParen) {
        int numOpenParen = 0, numClosedParen = 0;
        for (int i = iStart; i < s.length(); i++) {
            if (s[i] == openParen) numOpenParen++;
            if (s[i] == closeParen) numClosedParen++;
            if (numClosedParen > numOpenParen) {
                for (int j = jStart; j <= i; j++) {
                    if (s[j] == closeParen && (j == jStart || s[j - 1] != closeParen))
                        remove(s.substr(0, j) + s.substr(j + 1, s.length() - j - 1), ans, i, j, openParen, closeParen);
                }
                return;
            }
        }
        reverse(s.begin(), s.end());
        if (openParen == '(') {
            remove(s, ans, 0, 0, ')', '(');
        } else {
            ans.push_back(s);
        }
    }
};
