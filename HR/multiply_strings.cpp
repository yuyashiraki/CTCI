class Solution {
public:
    // Time O(n*m)  Space O(1)
    string multiply(string num1, string num2) {
        string sum(num1.size() + num2.size(), '0');
        int i, j, carry, pos = 0;
        for (i = num1.size() - 1; i >= 0; i--) {
            carry = 0;
            for (j = num2.size() - 1; j >= 0; j--) {
                int tmp = (num1[i] - '0')*(num2[j] - '0') + sum[i+j+1] - '0' + carry;
                sum[i+j+1] = (tmp % 10) + '0';
                carry = tmp / 10;
            }
            sum[i] = carry + '0';
        }
        cout << sum << endl;
        while ('0' == sum[pos]) pos++;
        if (pos == sum.size()) return "0";
        return sum.substr(pos, sum.size() - pos);
    }
};
