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
#include <tuple>
#include <regex>
using namespace std;

#define W 0
#define E 1

int main()
{
    int N, count = 0;
    string S;
    cin >> N;
    int ppl[N];
    cin >> S;
    for (int i = 0; i < N; i++) {
        switch(S[i]) {
            case 'W':
                ppl[i] = W;
                break;
            case 'E':
                ppl[i] = E;
                count++;
                break;
            default:
                cout << "ERROR" << endl;
                return 1;
        }
    }
    if (E == ppl[0]) count--;
    int rt = count;
    for (int i = 0; i < N - 1; i++) {
        if (E == ppl[i + 1]) {
            count--;
        }
        if (W == ppl[i]) {
            count++;
        }
        rt = min(rt, count);
    }
    cout << rt << endl;
    return 0;
}
