class Solution {
public:
    // DP + stack
    // Time O(n)  Space O(n)
    int longestValidParentheses(string s) {
        int i;
        vector<int> DP(s.size(), 0);
        stack<int> STK;
        int ans = 0;
        for (i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                STK.push(i);
            } else if (STK.empty()) {
                continue;
            } else {
                int prev = STK.top();
                STK.pop();
                DP[i] = i - prev + 1;
                if (prev > 0) DP[i] += DP[prev - 1];
                ans = max(ans, DP[i]);
            }
        }
        return ans;
    }

    // only stack
    // Time O(n)  Space O(n)
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> STK;
        STK.push(-1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                STK.push(i);
            } else {
                STK.pop();
                if (STK.empty()) STK.push(i);
                else ans = max(ans, i - STK.top());
            }
        }
        return ans;
    }

    // DP
    // Time O(n)  Space O(n)
    int longestValidParentheses(string s) {
        int ans = 0;
        vector<int> DP(s.size(), 0);
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ')' && i - DP[i - 1] - 1 >= 0 && s[i - DP[i - 1] - 1] == '(') {
                DP[i] = DP[i - 1] + 2;
                if (i - DP[i] >= 0) DP[i] += DP[i - DP[i]];
                ans = max(ans, DP[i]);
            }
        }
        return ans;
    }

    // two pass
    // Time O(n)  Space O(1)
    int longestValidParentheses(string s) {
        int left = 0, right = 0, ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') left++;
            else right++;
            if (left == right) ans = max(ans, 2 * right);
            else if (right > left) left = right = 0;
        }
        left = right = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(') left++;
            else right++;
            if (left == right) ans = max(ans, 2 * left);
            else if (left > right) left = right = 0;
        }
        return ans;
    }
};
