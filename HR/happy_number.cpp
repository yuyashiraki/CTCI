class Solution {
public:
    // using unordered_set
    // Time ?  Space O(infinity)
    unordered_set<int> st;
    bool isHappy(int n) {
        /*
          Continue replacing the number by the sum of the squares of its digits until the number equals 1.
         */
         //cout << n << endl;
         if (st.find(n) != st.end()) return false;
         if (n == 1) return true;
         st.insert(n);
         int digit, nx = 0;
         while (n) {
             digit = n % 10;
             nx += digit * digit;
             n /= 10;
         }
         return isHappy(nx);
    }

    // using slow, fast pointers
    // Time ?  Space O(1)
    int digitSquareSum(int n) {
        int digit, nx = 0;
        while (n) {
            digit = n % 10;
            nx += digit * digit;
            n /= 10;
        }
        return nx;
    }
    bool isHappy(int n) {
        int slow, fast;
        slow = fast = n;
        do {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(digitSquareSum(fast));
        } while (slow != fast);
        if (slow == 1) return 1;
        else return 0;
    }
};
