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
    int N, rt = 0;
    cin >> N;
    char c;
    map<char, vector<int> > mp;
    map<int, bool> line;
    for (int i = 0; i < N; i++) {
        cin >> c;
        mp[c].push_back(i);
    }
    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        if (itr->second.size() > 1) {
            line[itr->second.front()] = true;
            line[itr->second.back()] = false;
        }
    }
    int count = 0;
    for (auto itr = line.begin(); itr != line.end(); ++itr) {
        if (itr->second) count++;
        else count--;
        rt = max(rt, count);
    }
    cout << rt << endl;
    return 0;
}
