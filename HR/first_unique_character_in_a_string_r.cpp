class Solution {
public:
    // using Table to counter
    // Time O(n)  Space O(26)
    int firstUniqChar(string s) {
        vector<int> counter(26,0);
        for (int i = 0; i < s.size(); i++) {
            counter[s[i] - 'a']++;
        }
        int ans = s.size();
        for (int i = 0; i < s.size(); i++) {
            if (counter[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};
