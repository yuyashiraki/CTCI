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

#define ELEM 3

bool grt(ll i, ll j) {
    return (i > j);
}

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<vector<ll> > A(pow(2, ELEM), vector<ll>());
    ll rt = 0;
    for (ll i = 0; i < N; i++) {
        ll e[ELEM];
        for (ll j = 0; j < ELEM; j++) {
            cin >> e[j];
        }
        for (ll j = 0; j < pow(2, ELEM); j++) {
            ll d = 0;
            for (ll k = 0; k < ELEM; k++) {
                d += pow(-1, (j >> k) & 1) * e[k];
            }
            A[j].push_back(d);
        }
    }
    for (ll i = 0; i < pow(2, ELEM); i++) {
        sort(A[i].begin(), A[i].end(), grt);
        ll tmp = 0;
        for (ll j = 0; j < M; j++) tmp += A[i][j];
        rt = max(tmp, rt);
    }
    cout << rt << endl;
    return 0;
}
