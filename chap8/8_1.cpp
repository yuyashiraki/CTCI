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

int tripleStep(int n)
{
    int ways[n + 1] = {0, 1};
    for (int i = 1; i <= n; i++) {
        ways[i] += ways[i - 1];
        if (i > 1)
            ways[i] += ways[i - 2];
        if (i > 2)
            ways[i] += ways[i - 3];
    }
    return ways[n];
}

int main()
{
    cout << tripleStep(15) << endl;
    return 0;
}
