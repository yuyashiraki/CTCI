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

// recursive fibonacci
// Time O(2^n)  Space O(n)
int fibonacci(int i)
{
    if (i == 0) return 0;
    if (i == 1) return 1;
    return fibonacci(i - 1) + fibonacci(i - 2);
}

// memoization fibonacci
// Time O(n)  Space O(n)
// Each fibonacci(i, memo) is called once
int fibonacci(int n)
{
    return fibonacci(n, new int[n+1]);
}
int fibonacci(int i, int[] memo)
{
    if (i == 0 || i == 1) return i;
    if (memo[i] == 0) {
        memo[i] = fibonacci(i - 1, memo) + fibonacci(i - 2, memo);
    }
    return memo[i];
}

// Bottom-Up DP fibonnaci
int fibonacci(int n)
{
    if (n == 0) return 0;
    else if (n == 1) return 1;

    int[] memo = new int[n];
    memo[0] = 0;
    memo[1] = 1;
    for (int i = 2; i < n; i++) {
        memo[i] = memo[i - 1] + memo[i - 2];
    }
    return memo[n-1] + memo[n-2];
}
int fibonacci(int n)
{
    if (n == 0) return 0;
    int a = 0, b = 1;
    for (int i = 2; i < n; i++) {
        int c = a + b;
        a = b;
        b = c;
    }
    return a + b;
}

int main()
{
    return 0;
}
