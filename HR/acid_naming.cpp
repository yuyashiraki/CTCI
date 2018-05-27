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
    while (n--) {
        string s;
        cin >> s;
        regex acid(".+ic$");
        regex nonmetal("^hydro.+");
        if (regex_match(s, acid)) {
            if (regex_match(s, nonmetal)) {
                cout << "non-metal acid" << endl;
            } else {
                cout << "polyatomic acid" << endl;
            }
        } else {
            cout << "not an acid" << endl;
        }
    }
    return 0;
}
