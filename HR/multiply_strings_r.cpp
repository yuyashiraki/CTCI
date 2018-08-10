class Solution {
public:
    // Time O(nm)  Space O(n + m)
    string multiply(string num1, string num2) {
        string ans(num1.size() + num2.size(), '0');
        int i, j, carry = 0, pos;
        for (i = num1.size() - 1; i >= 0; i--) {
            for (j = num2.size() - 1; j >= 0; j--) {
                pos = i + j + 1;
                carry += ans[pos] - '0' + (num1[i] - '0') * (num2[j] - '0');
                ans[pos] = (char)('0' + carry % 10);
                carry /= 10;
            }
            while (carry) {
                pos--;
                carry += ans[pos] - '0';
                ans[pos] = (char)('0' + carry % 10);
                carry /= 10;
            }
        }
        while (pos < ans.size() - 1 && ans[pos] == '0') pos++;
        return ans.substr(pos, ans.size() - pos);
    }
};
