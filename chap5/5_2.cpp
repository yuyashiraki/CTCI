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

string BinaryToString(double x)
{
    if (x >= 1 || x <= 0) {
        return "ERROR";
    }

    string rt = ".";
    int cnt = 1;
    double cmp = 1;
    while (cnt++ < 32) {
        cmp /= 2;
        if (x >= cmp) {
            x -= cmp;
            rt += "1";
        } else {
            rt += "0";
        }
        if (!x) return rt;
    }
    return "ERROR";
}

int main()
{
    cout << BinaryToString(0.75) << endl;
    return 0;
}
