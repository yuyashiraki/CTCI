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
#include <sstream>

#define ll long long

using namespace std;

// Recursion
// Time O(2^n)  Space O(n)
int Fibonacci(int n) {
    if (n <= 1) return n;
    return Fibonnaci(n - 1) + Fibonnaci(n - 2);
}

// DP
// Time O(n)  Space O(n)
vector<ll> DP{1,1};
int Fibonacci(int N) {
    for (int i = DP.size(); i < N; i++) {
        DP.push_back((DP[i - 2] + DP[i - 1]) % 1000000007);
    }
    return DP[N - 1];
}

// DP
// Time O(n)  Space O(1)
int Fibonacci(int n) {
    int a = 0, b = 1;
    if (n == 0) return a;
    for (int i = 2; i <= n; i++) {
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// using power of matrix
// {{1,1},{1,0}}^n = {{Fn+1, Fn},{Fn,Fn-1}}
int Fibonacci(int n) {
    if (n == 0) return 0;
    int F[2][2] = {{1,1},{1,0}}, M[2][2] = {{1,1},{1,0}};
    for (int i = 2; i <= n; i++) {
        int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
        int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
        int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
        int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];
        F[0][0] = x;
        F[0][1] = y;
        F[1][0] = z;
        F[1][1] = w;
    }
    return F[0][0];
}

int main()
{
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        cout << Fibonacci(N) << endl;
    }
    return 0;
}
