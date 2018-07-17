class Solution {
public:
    // prime factorization  <-- TLE
    // Time O(n) Space O(1)
    bool isPerfectSquare(int num) {
        int div = 2, cnt = 0;
        while (num) {
            if (num == 1) break;
            cnt = 0;
            while (0 == num % div) {
                cnt++;
                num /= div;
            }
            //cout << num << " " << div << " " << cnt << endl;
            if (cnt % 2) {
                return false;
            }
            div++;
        }
        return true;
    }

    // Using rule of
    // 1^2 = 1, 2^2 = 1+3, 3^2 = 1+3+5, 4^2 = 1+3+5+7, 5^2 = 1+3+5+7+9
    // Time O(n) Space O(1)
    bool isPerfectSquare(int num) {
        int i = 1;
        while (num > 0) {
            num -= i;
            i += 2;
        }
        return num == 0;
    }

    // Binary Search
    // Time O(log(n)) Space O(1)
    bool isPerfectSquare(int num) {
        int low = 1, high =num;
        while (low <= high) {
            long mid = (low + high) / 2;
            if (mid * mid == num) {
                return true;
            } else if (mid * mid < num) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
};
