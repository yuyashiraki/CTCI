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

// Range based divide and conquer
// Time O(log(AB)*log(max - min))
int kth(vector<int>& A, vector<int>& B, int k)
{
        int lo = min(A[0], B[0]), hi = max(A[A.size() - 1], B[B.size() - 1]) + 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int pos = upper_bound(A.begin(), A.end(), mid) - A.begin();
            pos += upper_bound(B.begin(), B.end(), mid) - B.begin();
            if (pos < k) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
}

// index based divide and conquer
// Time O(log(min(A, B)))  Space O(1)
int kth(vector<int>& A, vector<int>& B, int k)
{
    if (A.size() > B.size()) {
        return kth(B, A, k);
    }
    int l1 = A.size(), l2 = B.size();
    int lo = 0, hi = l1;
    while (lo <= hi) {
        int left1 = lo + (hi - lo) / 2;
        int left2 = k - left1;
        while (left2 > l2) {
            left2--;
            left1++;
        }
        int maxleft1 = left1 == 0 ? INT_MIN : A[left1 - 1];
        int minright1 = left1 == l1 ? INT_MAX : A[left1];
        int maxleft2 = left2 == 0 ? INT_MIN : B[left2 - 1];
        int minright2 = left2 == l2 ? INT_MAX : B[left2];
        //cout << "DEBUG: (" << left1 << "," << maxleft1 << "), (" << left2 << maxleft2 << ")" << endl;
        if (maxleft1 <= minright2 && maxleft2 <= minright1) {
            return max(maxleft1, maxleft2);
        } else if (maxleft1 > minright2) {
            hi = left1 - 1;
        } else {
            lo = left1 + 1;
        }
    }
}

int main()
{
    int T, N, M, k;
    cin >> T;
    while (T--) {
        cin >> N >> M >> k;
        vector<int> A(N), B(M);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> B[i];
        }
        cout << kth(A, B, k) << endl;
    }
    return 0;
}
