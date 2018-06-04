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
#include <tuple>
#include <regex>

using namespace std;

/*
 * A: i < j < k && X[k] - X[i] <= D
 * B: i < j < k && X[j] - X[i] <= D && X[k] - X[j] <= D
 * return A -B
 *
 * A = left(i) C 2
 * B = left(m) * right(m)
 */

int N, D;
vector<int> X;
vector<pair<int, int> > LR;

int main()
{
    cin >> N >> D;
    for (int i = 0; i < N; i++) {
        int Xi;
        cin >> Xi;
        X.push_back(Xi);
    }
    /* binary search */
    int A = 0, B = 0;
    for (int i = 0; i < N - 1; i++) {
        int l, r, m, left, right;
        l = 0; r = i;
        while (l < r) {
            m = (l + r) / 2;
            if (X[i] - X[m] <= D) {
                r = m;
            } else {
                l = ++m;
            }
        }
        left = i - m;
        l = i + 1; r = N;
        while (l < r) {
            m = (l + r) / 2;
            //cout << l << " " << r << endl;
            if (X[m] - X[i] <= D) {
                l = ++m;
            } else {
                r = m;
            }
        }
        right = m - i - 1;
        LR.push_back(make_pair(left, right));
        //cout << left << " " << right << endl;
    }
    for (int i = 0; i < N - 1; i++) {
        if (LR[i].second)
            A += LR[i].second * (LR[i].second - 1) / 2;
        B += LR[i].first * LR[i].second;
    }
    cout << B - A << endl;
    return 0;
}
