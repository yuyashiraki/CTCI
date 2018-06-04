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
    int A, B, N;
    string X;
    cin >> A >> B >> N >> X;
    for (int i = 0; i < N; i++) {
        switch(X[i]) {
            case 'S':
                if (A) {
                    A--;
                }
                break;
            case 'C':
                if (B) {
                    B--;
                }
                break;
            case 'E':
                if ((A > B) || (A && A == B)) {
                    A--;
                } else if (B > A) {
                    B--;
                }
                break;
            default:
                assert(false);
                return 1;
        }
    }
    cout << A << endl;
    cout << B << endl;
    return 0;
}
