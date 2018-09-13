class Solution {
public:
    // dividing by each digit factorial
    // Time O(n)  Space O(n)
    string getPermutation(int n, int k) {
        k--;
        vector<int> nums;
        int factorial = 1;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
            factorial *= i;
        }
        string ans = "";
        while (n) {
            factorial /= n;
            n--;
            int x = k / factorial;
            k %= factorial;
            ans += to_string(nums[x]);
            nums.erase(nums.begin() + x);
        }
        return ans;
    }
};
