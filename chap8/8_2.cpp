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

// r rows, c columns
int robotInGrid(int r, int c) {
    int ways[c] = {1};
    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            // if cannot step (x, y): ways[y] = 0;
            if (x > 0)
                ways[x] += ways[x - 1];
        }
    }
    return ways[c - 1];
}

int main()
{
    cout << robotInGrid(3, 3) << endl;
    return 0;
}
