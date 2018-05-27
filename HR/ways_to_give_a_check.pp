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
#include <tuple>
#include <iterator>
#include <regex>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string board[8];
        int P;
        tuple<int, int> k;
        vector<tuple<int, int> > white_pieces, black_pieces;
        for (int i = 0; i < 8; i++) {
            cin >> board[i];
            for (int j = 0; j < 8; j++) {
                if ('#' == board[i][j]) continue;
                char p = board[i][j];
                if (p == 'P' && i == 1) P = j;
                else if (p == 'k') k = make_tuple(i, j);
                else if (p == 'K' || p == 'Q' || p == 'N' || p == 'B' || p == 'R' || p == 'P') white_pieces.append(make_tuple(i, j));
                else if (p == 'q' || p == 'n' || p == 'b' || p == 'r' || p == 'p') black_pieces.append(make_tuple(i, j));
                else continue;
            }
        }
    }
    return 0;
}
