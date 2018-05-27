/*
 * (a + b) - (a xor b) = 2 * (a and b)
 *  e.g. 0111 + 1010 - 1101 = 2 * 0010
 * Use two pointers technique.
 */
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
#include <tuple>
#include <string>
#include <iterator>
#include <regex>
using namespace std;

#define MAX_N 200000

int main()
{
    int N;
    cin >> N;
    int A[MAX_N];
    for (int i = 0; i < N; i++) {
        int Ai;
        cin >> Ai;
        A[i] = Ai;
    }

    int rt = 0, l = 0, r = 0, bin_or = 0;
    for (; l < N; l++) {
        while (r < N && !(bin_or & A[r])) {
            bin_or |= A[r];
            r++;
        }
        rt += r - l;
        bin_or = bin_or & ~A[l];
        //cout << "(l, r, rt, bin_or) = " << l << " " << r << " " << rt << " " << bin_or << endl;
    }
    cout << rt << endl;
    return 0;
}
