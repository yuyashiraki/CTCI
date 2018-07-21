class Solution {
public:
    // Expand around center 
    // Time O(n^2)  Space O(1)
    int countSubstrings(string s) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            cnt++;
            int x = i, y = i;
            while (x - 1 >= 0 && y + 1 < s.size() && s[x - 1] == s[y + 1]) {
                x--; y++;
                cnt++;
                //cout << "DEBUG1" << endl;
            }
        }
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == s[i + 1]) cnt++;
            else continue;
            int x = i, y = i + 1;
            while (x - 1 >= 0 && y + 1 < s.size() && s[x - 1] == s[y + 1]) {
                x--; y++;
                cnt++;
                //cout << "DEBUG2" << endl;
            }
        }
        return cnt;
    }
};
