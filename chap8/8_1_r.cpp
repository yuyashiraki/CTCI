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

#define ll long long

using namespace std;

// recursive
/*
int countWays(int n)
{
    if (n < 0) {
        return 0;
    } else if (n == 0) {
        return 1;
    } else {
        return countWays(n - 1) + countWays(n - 2) + countWays(n - 3);
    }
}
*/
int countWays(int n);
int countWays(int n, int memo[]);

// memoization
int countWays(int n)
{
    int memo[n + 1] = {};
    return countWays(n, memo);
}
int countWays(int n, int memo[])
{
    if (n < 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else if (memo[n] == 0) {
        memo[n] = countWays(n - 1, memo) + countWays(n-2, memo) + countWays(n-3, memo);
    }
    return memo[n];
}

int main()
{
    cout << countWays(15) << endl;
    return 0;
}
