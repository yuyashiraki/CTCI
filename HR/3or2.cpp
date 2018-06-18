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

int main()
{
    ll N, cnt = 0;
    cin >> N;
    for (ll i = 0; i < N; i++) {
        int a;
        cin >> a;
        while (a % 2 == 0) {
            cnt++;
            a /= 2;
        }
    }
    cout << cnt << endl;
    return 0;
}
