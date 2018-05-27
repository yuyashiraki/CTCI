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
#include <regex>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int minimum = 0, maximum = 0;
    int before = 0;
    for (int i = 0; i < n; i++) {
        int cur;
        cin >> cur;
        if (cur > 0) {
            maximum++;
            if (before == 0) {
                minimum++;
            }
        }
        if (before > 0) {
            before = 0;
        } else {
            before = cur;
        }
    }
    cout << minimum << " " << maximum << endl;
    return 0;
}
