// Brute force
// Time O(n^2)  Space O(1)
int countPrimes(int n) {
    int ans = 0;
    for (int i = 2; i < n; i++) {
        bool flg = true;
        for (int j = 2; j*j <= i; j++) {
            if (0 == i%j) flg = false;
        }
        if (flg) ans++;
    }
    return ans;
}

#define MAX_N 10000000
int countPrimes(int n) {
    bool mark[MAX_N] = {false};
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
