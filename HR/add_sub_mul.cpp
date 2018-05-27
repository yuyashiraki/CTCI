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

int main()
{
    int A, B;
    cin >> A >> B;
    int rt;
    rt = max(A + B, A - B);
    rt = max(rt, A * B);
    cout << rt << endl;
    return 0;
}
