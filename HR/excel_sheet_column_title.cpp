class Solution {
public:
    // iterative
    // Time O(digits)  Space O(1)
    string convertToTitle(int n) {
        string ans = "";
        while (n) {
            char x;
            if (n % 26) x = (n % 26) - 1 + 'A';
            else x = 'Z';
            n /= 26;
            if (x == 'Z') {
                n--;
            }
            ans = x + ans;
        }
        return ans;
    }
};
