class Solution {
public:
    // Two pointer
    // Time O(n)  Space O(1)
    void nextchar(const string &S, int &idx) {
        int cum = 0;
        while (idx >= 0) {
            if ('#' == S[idx]) {
                idx--;
                cum++;
                continue;
            }
            if (cum > 0) {
                cum--;
                idx--;
                continue;
            }
            return;
        }
    }
    bool backspaceCompare(string S, string T) {
        int sidx = S.size() - 1, tidx = T.size() - 1, scum = 0, tcum = 0;
        while (sidx >= 0 || tidx >= 0) {
            nextchar(S, sidx);
            nextchar(T, tidx);
            if (sidx < 0 || tidx < 0) break;
            if (S[sidx--] == T[tidx--]) continue;
            return false;
        }
        if (sidx == -1 && tidx == -1) {
            return true;
        } else {
            return false;
        }
    }
};
