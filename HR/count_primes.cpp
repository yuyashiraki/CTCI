class Solution {
public:
    // Sieve of Eratosthenes
    // Time O(nlog(log(n)))  Space O(n)
    int countPrimes(int n) {
        vector<bool> mark(n + 1, false);
        int ans = 0;
        for (int i = 2; i < n; i++) {
            if (mark[i]) continue;
            for (int j = i; j < n; j += i) {
                mark[j] = true;
            }
            ans++;
        }
        return ans;
    }
};
