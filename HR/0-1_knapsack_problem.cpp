#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <string>
#include <iterator>
#include <pthread.h>

#define ll long long

using namespace std;

// DP
// Time O(N*W)  Space O(N*W)
int knapsack(vector<int>& V, vector<int>& wt, int W, int N) {
    vector<vector<int>> dp(N+1, vector<int>(W+1, 0));
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= W; j++) {
            if (wt[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], V[i - 1] + dp[i - 1][j- wt[i - 1]]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
            //cout << i << " " << j << " dp:" << dp[i][j] << endl;
        }
    }
    return dp[N][W];
}

// Recursion + Memo
// Time O(N*W)  Space O(N*W)

int knapsack(vector<int>& V, vector<int>& wt, vector<vector<int>> memo, int W, int N) {
    if (memo[N][W] != -1) return memo[N][W];
    //cout << N << " " << W << endl;
    int ans = knapsack(V,wt,memo,W,N-1);
    if (W >= wt[N - 1]) {
        ans = max(ans, V[N - 1] + knapsack(V,wt,memo,W-wt[N - 1],N-1));
    }
    return memo[N][W] = ans;
}
int main() {
    int T, N, W, i, ans;
    cin >> T;  // #test cases
    while (T--) {
        cin >> N;   // #items
        cin >> W;   // max knapsack capacity
        vector<int> V(N);
        vector<int> wt(N);
        vector<vector<int>> memo(N+1, vector<int>(W+1, -1));
        for (int i = 0; i < N; i++) {
            cin >> V[i];
            memo[i][0] = 0;
        }
        memo[N][0] = 0;
        for (int i = 0; i < N; i++) {
            cin >> wt[i];
        }
        for (int i = 0; i < W + 1; i++) {
            memo[0][i] = 0;
        }
        //ans = knapsack(V,wt,memo,W,N);
        ans = knapsack(V,wt,W,N);
        cout << ans << endl;
    }
}
