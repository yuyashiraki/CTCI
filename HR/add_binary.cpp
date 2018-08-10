class Solution {
public:
    // traversing one by one
    // Time O(n)  Space O(1)
    string addBinary(string a, string b) {
        string ans = "";
        int aidx = a.size() - 1, bidx = b.size() - 1, carry = 0;
        while (aidx >= 0 || bidx >= 0 || carry) {
            if (aidx >= 0) carry += a[aidx] - '0';
            if (bidx >= 0) carry += b[bidx] - '0';
            if (carry % 2) {
                ans = "1" + ans;
            } else {
                ans = "0" + ans;
            }
            carry /= 2;
            aidx--; bidx--;
        }
        return ans;
    }
};
