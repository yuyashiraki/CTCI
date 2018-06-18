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

//signed main()
int main()
{
    ll D, N;
    cin >> D >> N;
/*
 * 1,2,3,...,99,101,102,...,199,201,...
 */
    if (100 == N) N = 101;
    ll rt = pow(100, D) * N;
    printf("%lld\n", rt);
    return 0;
}
