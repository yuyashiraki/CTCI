class Solution {
public:
    // using stack
    // Time: O(N)  Space: O(N)
    bool isValid(string s) {
        stack<int> stk; // (): 0, {}: 1, []: 2
        for (int i = 0; i < s.size(); i++) {
            switch(s[i]) {
                case '(':
                    stk.push(0);
                    break;
                case ')':
                    if (stk.empty() || stk.top() != 0) return false;
                    stk.pop();
                    break;
                case '{':
                    stk.push(1);
                    break;
                case '}':
                    if (stk.empty() || stk.top() != 1) return false;
                    stk.pop();
                    break;
                case '[':
                    stk.push(2);
                    break;
                case ']':
                    if (stk.empty() || stk.top() != 2) return false;
                    stk.pop();
                    break;
                default:
                    return false;
            }
        }
        if (stk.empty()) return true;
        else return false;
    }
};
