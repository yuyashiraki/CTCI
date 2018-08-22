class Solution {
public:
    // one pass
    // Time O(n)  Space O(1)
    int reverse(int x) {
        int sign = x < 0 ? -1 : 1;
        x = abs(x);
        long long ans = 0;
        while (x > 0) {
            ans *= 10;
            ans += x % 10;
            x /= 10;
        }
        if (ans < INT_MIN || ans > INT_MAX) return 0;
        return (int)sign * ans;
    }
};
