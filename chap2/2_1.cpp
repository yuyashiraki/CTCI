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
    int n, e;
    cin >> n;
    while (n--) {
        cin >> e;
        lst.push_back(e);
    }
    list<int>::iterator cur, ptr;
    for (cur = lst.begin(); cur != lst.end(); ++cur) {
        for (ptr = next(cur, 1); ptr != lst.end(); ++ptr) {
            if (*cur == *ptr) {
                cout << *cur << endl;
            }
        }
    }
    return 0;
}
