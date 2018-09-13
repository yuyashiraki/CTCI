class Solution {
public:
    // Count and Sort
    // Time O(S + T)  Space O(26)
    string customSortString(string S, string T) {
        vector<int> counts(26,0);
        string ans = "";
        for (int i = 0; i < T.size(); i++) {
            counts[T[i] - 'a']++;
        }
        for (int i = 0; i < S.size(); i++) {
            while (counts[S[i] - 'a']-- > 0) {
                ans += S[i];
            }
        }
        for (int i = 0; i < 26; i++) {
            while (counts[i]-- > 0) {
                ans += (char) ('a' + i);
            }
        }
        return ans;
    }
};
