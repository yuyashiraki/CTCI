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
using namespace std;

int FlipBitToWin(int x)
{
    int prev = 0;
    int cur  = 0;
    int mx  = 0;
    bool flg = false;
    for (int i = 0; (i < sizeof(int) * 8); i++) {
        if (x & 1) {
            cur += 1;
            flg = true;
        } else {
            mx   = max(prev + 1 + cur, mx);
            prev = cur;
            cur  = 0;
        }
        x = x >> 1;
    }
    return mx;
}

int main()
{
    int x;
    cin  >> x; 
    cout << FlipBitToWin(x) << endl;
    return 0;
}
