class Solution {
public:
    // Two pointers
    // Time O(n)  Space O(log10(n))
    int compress(vector<char>& chars) {
        int top = 0, cnt = 1;
        for (int i = 1; i <= chars.size(); i++) {
            if (i != chars.size() && chars[i - 1] == chars[i]) cnt++;
            else {
                chars[top++] = chars[i - 1];
                if (cnt > 1) {
                    stack<char> STK;
                    while (cnt) {
                        STK.push((char)(cnt % 10 + '0'));
                        cnt = cnt / 10;
                    }
                    while (!STK.empty()) {
                        chars[top++] = STK.top();
                        STK.pop();
                    }
                }
                cnt = 1;
            }
        }
        return top;
    }
};
