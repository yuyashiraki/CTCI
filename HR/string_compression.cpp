class Solution {
public:
    // Time O(n)  Space O(1) if not stack
    int compress(vector<char>& chars) {
        if (chars.size() == 0) return 0;
        int top = 0, cnt = 0;
        char prev = chars[0];
        for (int cur = 0; cur <= chars.size(); cur++) {
            if (cur == chars.size() || prev != chars[cur]) {
                if (cnt == 1) {
                    chars[top++] = prev;
                } else {
                    chars[top++] = prev;
                    stack<int> STK;
                    while (cnt) {
                        STK.push(cnt % 10);
                        cnt /= 10;
                    }
                    while (!STK.empty()) {
                        chars[top++] = (char)(STK.top() + '0');
                        STK.pop();
                    }
                }
                prev = chars[cur];
                cnt = 1;
            } else {
                cnt++;
            }
        }
        return top;
    }
};
