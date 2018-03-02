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

int main()
{
    list<int> lst;
    int k, n, e;
    cin >> k >> n;
    while (n--) {
        cin >> e;
        lst.push_back(e);
    }
    list<int>::iterator cur = lst.begin(), ptr = next(cur, k);;
    while (ptr != lst.end()) {
        ++ptr;
        ++cur;
    }
    --cur;
    cout << *cur << endl;
    return 0;
}
